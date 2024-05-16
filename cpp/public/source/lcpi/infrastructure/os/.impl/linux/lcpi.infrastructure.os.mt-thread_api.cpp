////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. Atomic functions.
//                                                 Kovalenko Dmitry. 15.03.2024.
#include <_pch_.h>
//#pragma hdrstop

#include <lcpi/infrastructure/os/.impl/linux/lcpi.infrastructure.os.mt-thread_api.h>
#include <lcpi/lib/structure/t_smart_object_ptr.h>
#include <lcpi/lib/structure/t_smart_object.h>
#include <lcpi/lib/structure/t_memory.h>
#include <lcpi/lib/structure/t_negative_one.h>
#include <deque>
#include <atomic>
#include <future>
#include <mutex>
#include <map>
#include <algorithm>

#include <sys/time.h>

namespace lcpi{namespace infrastructure{namespace os{namespace mt{
////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi::ErrorUtils

class LCPI_OS__ThreadApi::ErrorUtils
{
 private:
  using self_type=ErrorUtils;

 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheckError
               (const char* bugcheck_src,
                const char* bugcheck_reason);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheckError__InvalidThreadHandle
               (const char* bugcheck_src);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheckError__InvalidEventHandle
               (const char* bugcheck_src);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheckError__UnknownWaitResult
               (const char* bugcheck_src,
                int         wait_result);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheckError__InvalidArgumentValue
               (const char* bugcheck_src,
                const char* argument_name,
                const char* argument_value);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheckError__WFME_Returned_Invalid_Object_Index
               (const char* bugcheck_src,
                size_t      objectCount,
                size_t      objectIndex);

 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowSystemError
               (int         r,
                const char* errDescr);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowSystemError__clock_gettime__failed
               (int r);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowSystemError__CreateThread__failed
               (int r);
};//class LCPI_OS__ThreadApi::ErrorUtils

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi::ErrorUtils

void LCPI_OS__ThreadApi::ErrorUtils::ThrowBugCheckError
               (const char* const bugcheck_src,
                const char* const bugcheck_reason)
{
 LCPI__assert(bugcheck_src);
 LCPI__assert(bugcheck_reason);

 std::string errMsg="[BUG CHECK][";

 errMsg+=bugcheck_src;
 errMsg+="] - ";
 errMsg+=bugcheck_reason;
 errMsg+=".";

 throw std::runtime_error(errMsg);
}//ThrowBugCheckError

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowBugCheckError__InvalidThreadHandle
               (const char* const bugcheck_src)
{
 LCPI__assert(bugcheck_src);

 self_type::ThrowBugCheckError
  (bugcheck_src,
   "Invalid thread handle");
}//ThrowBugCheckError__InvalidThreadHandle

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowBugCheckError__InvalidEventHandle
               (const char* const bugcheck_src)
{
 LCPI__assert(bugcheck_src);

 self_type::ThrowBugCheckError
  (bugcheck_src,
   "Invalid event handle");
}//ThrowBugCheckError__InvalidEventHandle

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowBugCheckError__UnknownWaitResult
               (const char* const bugcheck_src,
                int         const wait_result)
{
 LCPI__assert(bugcheck_src);

 const std::string
  errReason
   ="Unknown wait result code ["+std::to_string(wait_result)+"]";

 self_type::ThrowBugCheckError
  (bugcheck_src,
   errReason.c_str());
}//ThrowBugCheckError__UnknownWaitResult

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowBugCheckError__InvalidArgumentValue
               (const char* const bugcheck_src,
                const char* const argument_name,
                const char* const argument_value)
{
 LCPI__assert(bugcheck_src);
 LCPI__assert(argument_name);
 LCPI__assert(argument_value);

 std::string errReason;

 errReason ="An invalid argument [";
 errReason+=argument_name;
 errReason+="] value [";
 errReason+=argument_value;
 errReason+="]";

 self_type::ThrowBugCheckError
  (bugcheck_src,
   errReason.c_str());
}//ThrowBugCheckError__InvalidArgumentValue

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowBugCheckError__WFME_Returned_Invalid_Object_Index
               (const char* const bugcheck_src,
                size_t      const objectCount,
                size_t      const objectIndex)
{
 LCPI__assert(bugcheck_src);

 std::string errReason;

 errReason ="WaitForMultipleEvents returned an invalid objectIndex [";
 errReason+=std::to_string(objectIndex);
 errReason+="]. Event count is [";
 errReason+=std::to_string(objectCount);
 errReason+="]";

 self_type::ThrowBugCheckError
  (bugcheck_src,
   errReason.c_str());
}//ThrowBugCheckError__WFME_Returned_Invalid_Object_Index

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowSystemError
                        (int         const r,
                         const char* const errDescr)
{
 LCPI__assert(errDescr);

 throw std::system_error(r,std::system_category(),errDescr);
}//ThrowSystemError

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowSystemError__clock_gettime__failed
                        (int const r)
{
 ErrorUtils::ThrowSystemError
  (r,
   "The call of clock_gettime failed.");
}//ThrowSystemError__clock_gettime__failed

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowSystemError__CreateThread__failed
                        (int const r)
{
 ErrorUtils::ThrowSystemError
  (r,
   "Posix thread is not created.");
}//ThrowSystemError__CreateThread__failed

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi::EventApi

class LCPI_OS__ThreadApi::EventApi LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=EventApi;

 public:
  // Each call to WaitForMultipleObjects initializes a neosmart_wfmo_t object which tracks
  // the progress of the caller's multi-object wait and dispatches responses accordingly.
  // One neosmart_wfmo_t struct is shared for all events in a single WFMO call

  struct neosmart_wfmo_t_ LCPI_CPP_CFG__CLASS__FINAL
  {
   pthread_mutex_t Mutex;

   pthread_cond_t CVariable;

   std::atomic<size_t> RefCount;

   union
   {
    size_t FiredEvent; // WFSO
    size_t EventsLeft; // WFMO
   } Status;

   bool WaitAll;

   std::atomic<bool> StillWaiting;

   void Destroy()
   {
    pthread_mutex_destroy(&Mutex);
    pthread_cond_destroy(&CVariable);
   }
  };//struct neosmart_wfmo_t_

  using neosmart_wfmo_t=neosmart_wfmo_t_*;

 public:
  // A neosmart_wfmo_info_t object is registered with each event waited on in a WFMO
  // This reference to neosmart_wfmo_t_ is how the event knows whom to notify when triggered

 struct neosmart_wfmo_info_t_ LCPI_CPP_CFG__CLASS__FINAL
  {
   neosmart_wfmo_t Waiter;

   size_t WaitIndex;
  };//struct neosmart_wfmo_info_t_

  using neosmart_wfmo_info_t=neosmart_wfmo_info_t_*;

 public:
  // The basic event structure, passed to the caller as an opaque pointer when creating events

  struct neosmart_event_t_ LCPI_CPP_CFG__CLASS__FINAL
  {
   pthread_cond_t CVariable;

   pthread_mutex_t Mutex;

   bool AutoReset;

   std::atomic<bool> State;

   std::deque<neosmart_wfmo_info_t_> RegisteredWaits;
  };//struct neosmart_event_t_

  using neosmart_event_t=neosmart_event_t_*;

 public:
  static bool RemoveExpiredWaitHelper(neosmart_wfmo_info_t_ wait);

  static neosmart_event_t CreateEvent(bool manualReset, bool initialState);

  static int UnlockedWaitForEvent(neosmart_event_t event, TimeOut_t milliseconds);

  static int WaitForEvent(neosmart_event_t event, TimeOut_t milliseconds);

  static int WaitForMultipleEvents
                        (const neosmart_event_t* events,
                         size_t                  count,
                         bool                    waitAll,
                         TimeOut_t               milliseconds);

  static int WaitForMultipleEvents
                        (const neosmart_event_t* events,
                         size_t                  count,
                         bool                    waitAll,
                         TimeOut_t               milliseconds,
                         size_t&                 waitIndex);

  static void DestroyEvent(neosmart_event_t event);

  static void SetEvent(neosmart_event_t event);

  static void ResetEvent(neosmart_event_t event);
};//class LCPI_OS__ThreadApi::EventApi

////////////////////////////////////////////////////////////////////////////////
//LCPI_OS__ThreadApi::EventApi

bool LCPI_OS__ThreadApi::EventApi::RemoveExpiredWaitHelper(neosmart_wfmo_info_t_ wait)
{
 if(wait.Waiter->StillWaiting.load(std::memory_order_relaxed))
 {
  return false;
 }

 LCPI__assert(wait.Waiter->RefCount>0);

 const size_t
  ref_count
   =wait.Waiter->RefCount.fetch_sub(1, std::memory_order_acq_rel);

 LCPI__assert(ref_count > 0);

 if(ref_count == 1)
 {
  wait.Waiter->Destroy();

  delete wait.Waiter;
 }//if

 return true;
}//RemoveExpiredWaitHelper

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::EventApi::neosmart_event_t
 LCPI_OS__ThreadApi::EventApi::CreateEvent(bool manualReset, bool initialState)
{
 neosmart_event_t event=new neosmart_event_t_;

 LCPI__VERIFY_EQ(pthread_cond_init(&event->CVariable,0), 0);

 LCPI__VERIFY_EQ(pthread_mutex_init(&event->Mutex,0), 0);

 event->AutoReset=!manualReset;

 // memory_order_release: if `initialState == true`, allow a load with acquire semantics to
 // see the value.
 event->State.store(initialState, std::memory_order_release);

 return event;
}//CreateEvent

//------------------------------------------------------------------------
int LCPI_OS__ThreadApi::EventApi::UnlockedWaitForEvent
                        (neosmart_event_t const event,
                         TimeOut_t        const milliseconds)
{
 LCPI__assert(event);

 int result=0;

 // memory_order_relaxed: `State` is only set to true with the mutex held, and we require
 // that this function only be called after the mutex is obtained.

 if(!event->State.load(std::memory_order_relaxed))
 {
  // Zero-timeout event state check optimization

  if(milliseconds==0)
  {
   return ETIMEDOUT;
  }

  timespec ts;

  if(milliseconds!=LCPI_OS__ThreadApi::Infinite)
  {
   timeval tv;

   gettimeofday(&tv, nullptr);

   const uint64_t nanoseconds
    = ((uint64_t)tv.tv_sec) * 1000 * 1000 * 1000 + milliseconds * 1000 * 1000 + ((uint64_t)tv.tv_usec) * 1000;

   ts.tv_sec = (time_t) (nanoseconds / 1000 / 1000 / 1000);

   ts.tv_nsec = (long) (nanoseconds - ((uint64_t)ts.tv_sec) * 1000 * 1000 * 1000);
  }//if

  do
  {
   // Regardless of whether it's an auto-reset or manual-reset event:
   // wait to obtain the event, then lock anyone else out

   if(milliseconds!=LCPI_OS__ThreadApi::Infinite)
   {
    result = pthread_cond_timedwait(&event->CVariable, &event->Mutex, &ts);
   }
   else
   {
    result = pthread_cond_wait(&event->CVariable, &event->Mutex);
   }

   // memory_order_relaxed: ordering is guaranteed by the mutex, as `State = true` is
   // only ever written with the mutex held.
  }
  while (result == 0 && !event->State.load(std::memory_order_relaxed));
 }
 else
 if(event->AutoReset)
 {
  // It's an auto-reset event that's currently available;
  // we need to stop anyone else from using it

  LCPI__assert(result==0);

  result=0;
 }
 else
 {
  // We're trying to obtain a manual reset event with a signaled state; don't do anything
 }

 if(result == 0 && event->AutoReset)
 {
  // We've only accquired the event if the wait succeeded
  // memory_order_relaxed: we never act on `State == true` without fully synchronizing
  // or grabbing the mutex, so it's OK to use relaxed semantics here.

  event->State.store(false, std::memory_order_relaxed);
 }//if

 return result;
}//UnlockedWaitForEvent

//------------------------------------------------------------------------
int LCPI_OS__ThreadApi::EventApi::WaitForEvent
                             (neosmart_event_t const event,
                              TimeOut_t        const milliseconds)
{
 LCPI__assert(event);

 // Optimization: bypass acquiring the event lock if the state atomic is unavailable.
 // memory_order_relaxed: This is just an optimization, it's OK to be biased towards a stale
 // value here, and preferable to synchronizing CPU caches to get a more accurate result.

 if(milliseconds == 0 && !event->State.load(std::memory_order_relaxed))
 {
  return ETIMEDOUT;
 }
 // Optimization: early return in case of success for manual reset events only.

 if(!event->AutoReset && event->State.load(std::memory_order_relaxed))
 {
  // A memory barrier is required here. This is still cheaper than a syscall.
  // See https://github.com/neosmart/pevents/issues/18

  if(event->State.load(std::memory_order_acquire))
  {
   return 0;
  }
 }//if

 LCPI__VERIFY_EQ(pthread_mutex_lock(&event->Mutex), 0);

 const int result
  =UnlockedWaitForEvent(event, milliseconds);

 LCPI__VERIFY_EQ(pthread_mutex_unlock(&event->Mutex), 0);

 return result;
}//WaitForEvent

//------------------------------------------------------------------------
int LCPI_OS__ThreadApi::EventApi::WaitForMultipleEvents
                             (const neosmart_event_t* const events,
                              size_t                  const count,
                              bool                    const waitAll,
                              TimeOut_t               const milliseconds)
{
 size_t unused=size_t(-1);

 return self_type::WaitForMultipleEvents
         (events,
          count,
          waitAll,
          milliseconds,
          unused);
}//WaitForMultipleEvents

//------------------------------------------------------------------------
int LCPI_OS__ThreadApi::EventApi::WaitForMultipleEvents
                             (const neosmart_event_t* const events,
                              size_t                  const count,
                              bool                    const waitAll,
                              TimeOut_t               const milliseconds,
                              size_t&                       waitIndex)
{
 LCPI__assert(count>0);

 LCPI__CHECK_READ_TYPED_PTR(events,count);

 neosmart_wfmo_t wfmo = new neosmart_wfmo_t_;

 LCPI__VERIFY_EQ(pthread_mutex_init(&wfmo->Mutex, 0), 0);

 LCPI__VERIFY_EQ(pthread_cond_init(&wfmo->CVariable, 0), 0);

 neosmart_wfmo_info_t_ waitInfo;

 waitInfo.Waiter = wfmo;

 waitInfo.WaitIndex = lib::structure::negative_one;

 if(waitAll)
 {
  wfmo->Status.EventsLeft=count;
 }
 else
 {
  wfmo->Status.FiredEvent=(size_t)-1;
 }

 wfmo->WaitAll=waitAll;

 wfmo->StillWaiting.store(true, std::memory_order_release);

 // memory_order_release: this is the initial value other threads should see
 wfmo->RefCount.store(1 + count, std::memory_order_release);

 // Separately keep track of how many refs to decrement after the initialization loop, to
 // avoid repeatedly clearing the cache line.
 size_t skipped_refs = 0;

 LCPI__VERIFY_EQ(pthread_mutex_lock(&wfmo->Mutex), 0);

 bool done=false;

 waitIndex=lib::structure::negative_one;

 for(size_t i=0;i<count;++i)
 {
  waitInfo.WaitIndex = i;

  // Skip obtaining the mutex for manual reset events. This requires a memory barrier to
  // ensure correctness.
  bool skipLock = false;

  if(!events[i]->AutoReset)
  {
   if(events[i]->State.load(std::memory_order_relaxed) && events[i]->State.load(std::memory_order_acquire))
   {
    skipLock = true;
   }
  }

  if(!skipLock)
  {
   // Must not release lock until RegisteredWait is potentially added

   LCPI__VERIFY_EQ(pthread_mutex_lock(&events[i]->Mutex), 0);

   // Before adding this wait to the list of registered waits, let's clean up old,
   // expired waits while we have the event lock anyway.

   events[i]->RegisteredWaits.erase
     (std::remove_if
        (events[i]->RegisteredWaits.begin(),
         events[i]->RegisteredWaits.end(),
         self_type::RemoveExpiredWaitHelper),
      events[i]->RegisteredWaits.end());
  }//if

  if(skipLock || UnlockedWaitForEvent(events[i], 0)==0)
  {
   if(!skipLock)
   {
    LCPI__VERIFY_EQ(pthread_mutex_unlock(&events[i]->Mutex), 0);
   }

   if(waitAll)
   {
    ++skipped_refs;

    LCPI__assert(wfmo->Status.EventsLeft > 0);

    --wfmo->Status.EventsLeft;

    //LCPI__assert(wfmo->Status.EventsLeft >= 0);
   }
   else
   {
    skipped_refs += (count - i);

    wfmo->Status.FiredEvent = i;

    waitIndex = i;

    done = true;

    break;
   }
  }
  else
  {
   events[i]->RegisteredWaits.push_back(waitInfo);

   LCPI__VERIFY_EQ(pthread_mutex_unlock(&events[i]->Mutex), 0);
  }//else
 }//for i

 // We set the `done` flag above in case of WaitAny and at least one event was set.
 // But we need to check again here if we were doing a WaitAll or else we'll incorrectly
 // return WAIT_TIMEOUT.

 if(waitAll && wfmo->Status.EventsLeft == 0)
 {
  done=true;
 }

 int result = 0;

 timespec ts;

 if(!done)
 {
  if(milliseconds==0)
  {
   result=ETIMEDOUT;

   done=true;
  }
  else
  if(milliseconds!=LCPI_OS__ThreadApi::Infinite)
  {
   timeval tv;

   gettimeofday(&tv, nullptr);

   const uint64_t nanoseconds
    = ((uint64_t)tv.tv_sec) * 1000 * 1000 * 1000 + milliseconds * 1000 * 1000 + ((uint64_t)tv.tv_usec) * 1000;

   ts.tv_sec = (time_t) (nanoseconds / 1000 / 1000 / 1000);
   ts.tv_nsec = (long) (nanoseconds - ((uint64_t)ts.tv_sec) * 1000 * 1000 * 1000);
  }
 }//if

 while(!done)
 {
  // One (or more) of the events we're monitoring has been triggered?

  // If we're waiting for all events, assume we're done and check if there's an event that
  // hasn't fired But if we're waiting for just one event, assume we're not done until we
  // find a fired event
  done = (waitAll && wfmo->Status.EventsLeft == 0) || (!waitAll && wfmo->Status.FiredEvent != size_t(-1));

  if(!done)
  {
   if(milliseconds!=LCPI_OS__ThreadApi::Infinite)
   {
    result=pthread_cond_timedwait(&wfmo->CVariable, &wfmo->Mutex, &ts);
   }
   else
   {
    result=pthread_cond_wait(&wfmo->CVariable, &wfmo->Mutex);
   }

   if(result!=0)
   {
    break;
   }
  }
 }//while

 waitIndex = wfmo->Status.FiredEvent;

 // memory_order_relaxed: this is only checked outside the mutex to determine if waiting has
 // terminated meaning it's safe to decrement the ref count. If it's true (which we write
 // with release semantics), then the mutex is always entered.

 wfmo->StillWaiting.store(false, std::memory_order_relaxed);

 LCPI__VERIFY_EQ(pthread_mutex_unlock(&wfmo->Mutex), 0);

 LCPI__assert(wfmo->RefCount>0);

 // memory_order_seq_cst: Ensure this is run after the wfmo mutex is unlocked
 const size_t ref_count
  =wfmo->RefCount.fetch_sub(1 + skipped_refs, std::memory_order_seq_cst);

 LCPI__assert(ref_count>0);

 if(ref_count == 1 + skipped_refs)
 {
  wfmo->Destroy();

  delete wfmo;
 }

 return result;
}//WaitForMultipleEvents

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::EventApi::DestroyEvent(neosmart_event_t const event)
{
 LCPI__assert(event);

 LCPI__VERIFY_EQ(pthread_mutex_lock(&event->Mutex), 0);

 event->RegisteredWaits.erase
  (std::remove_if
    (event->RegisteredWaits.begin(),
     event->RegisteredWaits.end(),
     RemoveExpiredWaitHelper),
   event->RegisteredWaits.end());

 LCPI__VERIFY_EQ(pthread_mutex_unlock(&event->Mutex), 0);

 LCPI__VERIFY_EQ(pthread_cond_destroy(&event->CVariable), 0);

 LCPI__VERIFY_EQ(pthread_mutex_destroy(&event->Mutex), 0);

 delete event;
}//DestroyEvent

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::EventApi::SetEvent(neosmart_event_t event)
{
 LCPI__assert(event);

 LCPI__VERIFY_EQ(pthread_mutex_lock(&event->Mutex), 0);

 // Depending on the event type, we either trigger everyone or only one
 if(event->AutoReset)
 {
   while(!event->RegisteredWaits.empty())
   {
    neosmart_wfmo_info_t i=&event->RegisteredWaits.front();

    // memory_order_relaxed: this is just an optimization to see if it is OK to skip
    // this waiter, and if it's observed to be false then it's OK to bypass the mutex at
    // that point.

    if(!i->Waiter->StillWaiting.load(std::memory_order_relaxed))
    {
     LCPI__assert(i->Waiter->RefCount>0);

     const size_t ref_count
      =i->Waiter->RefCount.fetch_sub(1, std::memory_order_acq_rel);

     LCPI__assert(ref_count > 0);

     if(ref_count==1)
     {
      i->Waiter->Destroy();

      delete i->Waiter;
     }

     event->RegisteredWaits.pop_front();

     continue;
    }//if

    LCPI__VERIFY_EQ(pthread_mutex_lock(&i->Waiter->Mutex), 0);

    // We have to check `Waiter->StillWaiting` twice, once before locking as an
    // optimization to bypass the mutex altogether, and then again after locking the
    // WFMO mutex because we could have !waitAll and another event could have ended the
    // wait, in which case we must not unlock the same waiter or else a SetEvent() call
    // on an auto-reset event may end up with a lost wakeup.

    if(!i->Waiter->StillWaiting.load(std::memory_order_relaxed))
    {
     LCPI__VERIFY_EQ(pthread_mutex_unlock(&i->Waiter->Mutex), 0);

     LCPI__assert(i->Waiter->RefCount>0);

     // memory_order_seq_cst: Ensure this is run after the wfmo mutex is unlocked
     const size_t ref_count
      =i->Waiter->RefCount.fetch_sub(1,std::memory_order_seq_cst);

     LCPI__assert(ref_count>0);

     if (ref_count==1)
     {
      i->Waiter->Destroy();

      delete i->Waiter;
     }

     event->RegisteredWaits.pop_front();

     continue;
    }//if

    if(i->Waiter->WaitAll)
    {
      LCPI__assert(i->Waiter->Status.EventsLeft > 0);

      --i->Waiter->Status.EventsLeft;

      //LCPI__assert(i->Waiter->Status.EventsLeft >= 0);

      // We technically should do i->Waiter->StillWaiting = Waiter->Status.EventsLeft
      // != 0 but the only time it'll be equal to zero is if we're the last event, so
      // no one else will be checking the StillWaiting flag. We're good to go without
      // it.
    }
    else
    {
     i->Waiter->Status.FiredEvent = i->WaitIndex;

     // memory_order_relaxed: The flip to false is only lazily observed as an
     // optimization to bypass the mutex for cleanup.

     i->Waiter->StillWaiting.store(false, std::memory_order_relaxed);
    }//else

    LCPI__VERIFY_EQ(pthread_mutex_unlock(&i->Waiter->Mutex), 0);

    LCPI__VERIFY_EQ(pthread_cond_signal(&i->Waiter->CVariable), 0);

    LCPI__assert(i->Waiter->RefCount>0);

    // memory_order_seq_cst: Ensure this is run after the wfmo mutex is unlocked
    const size_t
     ref_count
      =i->Waiter->RefCount.fetch_sub(1, std::memory_order_seq_cst);

    LCPI__assert(ref_count>0);

    if(ref_count==1)
    {
     i->Waiter->Destroy();

     delete i->Waiter;
    }

    event->RegisteredWaits.pop_front();

    LCPI__VERIFY_EQ(pthread_mutex_unlock(&event->Mutex), 0);

    return;
   }//while

   // memory_order_release: this is the synchronization point for any threads spin-waiting
   // for the event to become available.
   event->State.store(true, std::memory_order_release);

   LCPI__VERIFY_EQ(pthread_mutex_unlock(&event->Mutex), 0);

   LCPI__VERIFY_EQ(pthread_cond_signal(&event->CVariable), 0);
 }
 else
 {
  // this is a manual reset event
  // memory_order_release: this is the synchronization point for any threads spin-waiting
  // for the event to become available.

  event->State.store(true, std::memory_order_release);

  for(size_t i=0;i<event->RegisteredWaits.size();++i)
  {
   neosmart_wfmo_info_t const info=&event->RegisteredWaits[i];

   // memory_order_relaxed: this is just an optimization to see if it is OK to skip
   // this waiter, and if it's observed to be false then it's OK to bypass the mutex at
   // that point.

   if(!info->Waiter->StillWaiting.load(std::memory_order_relaxed))
   {
    LCPI__assert(info->Waiter->RefCount>0);

    const size_t ref_count
     =info->Waiter->RefCount.fetch_sub(1, std::memory_order_acq_rel);

    if (ref_count == 1)
    {
     info->Waiter->Destroy();

     delete info->Waiter;
    }

    continue;
   }//if

   LCPI__VERIFY_EQ(pthread_mutex_lock(&info->Waiter->Mutex), 0);

   // Waiter->StillWaiting may have become true by now, but we're just going to pretend
   // it hasn't. So long as we hold a reference to the WFMO, this is safe since manual
   // reset events are not one-time use.

   if(info->Waiter->WaitAll)
   {
    LCPI__assert(info->Waiter->Status.EventsLeft > 0);

    --info->Waiter->Status.EventsLeft;

    //LCPI__assert(info->Waiter->Status.EventsLeft >= 0);

    // We technically should do i->Waiter->StillWaiting = Waiter->Status.EventsLeft
    // != 0 but the only time it'll be equal to zero is if we're the last event, so
    // no one else will be checking the StillWaiting flag. We're good to go without
    // it.
   }
   else
   {
    info->Waiter->Status.FiredEvent = info->WaitIndex;

    // memory_order_relaxed: The flip to false is only lazily observed as an
    // optimization to bypass the mutex for cleanup.

    info->Waiter->StillWaiting.store(false, std::memory_order_relaxed);
   }

   LCPI__VERIFY_EQ(pthread_mutex_unlock(&info->Waiter->Mutex), 0);

   LCPI__VERIFY_EQ(pthread_cond_signal(&info->Waiter->CVariable), 0);

   LCPI__assert(info->Waiter->RefCount>0);

   // memory_order_seq_cst: Ensure this is run after the wfmo mutex is unlocked
   const size_t
    ref_count
     =info->Waiter->RefCount.fetch_sub(1, std::memory_order_seq_cst);

   LCPI__assert(ref_count>0);

   if(ref_count==1)
   {
    info->Waiter->Destroy();

    delete info->Waiter;
   }//if

   continue;
  }//for

  event->RegisteredWaits.clear();

  LCPI__VERIFY_EQ(pthread_mutex_unlock(&event->Mutex), 0);

  LCPI__VERIFY_EQ(pthread_cond_broadcast(&event->CVariable), 0);
 }//else

 return;
}//SetEvent

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::EventApi::ResetEvent(neosmart_event_t event)
{
 LCPI__assert(event);

 // memory_order_relaxed and no mutex: there can't be any guarantees about concurrent calls
 // to either of WFMO()/SetEvent() and ResetEvent() because they're racy by nature. Only the
 // behavior of concurrent WFMO() and SetEvent() calls is strongly defined.

 event->State.store(false, std::memory_order_relaxed);

 return;
}//ResetEvent

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi::ThreadWaiter

class LCPI_OS__ThreadApi::ThreadWaiter LCPI_CPP_CFG__CLASS__FINAL
 :public lib::structure::t_basic_smart_memory_object<lib::structure::t_void_allocator>
{
 private:
  using self_type=ThreadWaiter;

  ThreadWaiter(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr
   =lib::structure::t_smart_object_ptr<self_type>;

 private:
  explicit ThreadWaiter(pthread_t hThread);

 ~ThreadWaiter();

 public:
  static self_ptr Create(pthread_t hThread);

  static size_t GetInstanceCount();

  void FinalWait()const;

  std::shared_future<int> GetFutureCopy()const;

 private:
  static int Helper__Exec(self_type* const pThis);

 private:
  pthread_t const m_hThread;

  std::shared_future<int> m_future;

 private:
  static std::atomic<size_t> sm_cInstances;
};//class LCPI_OS__ThreadApi::ThreadWaiter

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi::ThreadWaiter

std::atomic<size_t>
 LCPI_OS__ThreadApi::ThreadWaiter::sm_cInstances(0);

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::ThreadWaiter::ThreadWaiter(pthread_t const hThread)
 :m_hThread(hThread)
{
 LCPI__assert(m_hThread!=pthread_t());

 m_future=std::async(std::launch::async,self_type::Helper__Exec,this); //throw

 ++sm_cInstances;
}//ThreadWaiter

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::ThreadWaiter::~ThreadWaiter()
{
 LCPI__assert(sm_cInstances>0);

 --sm_cInstances;
}//~ThreadWaiter

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::ThreadWaiter::self_ptr
 LCPI_OS__ThreadApi::ThreadWaiter::Create(pthread_t const hThread)
{
 return lib::structure::not_null_ptr(new self_type(hThread)); //throw
}//Create

//------------------------------------------------------------------------
size_t LCPI_OS__ThreadApi::ThreadWaiter::GetInstanceCount()
{
 return sm_cInstances.load();
}//GetInstanceCount

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ThreadWaiter::FinalWait()const
{
 m_future.wait();
}//FinalWait

//------------------------------------------------------------------------
std::shared_future<int> LCPI_OS__ThreadApi::ThreadWaiter::GetFutureCopy()const
{
 return m_future;
}//GetFutureCopy

//------------------------------------------------------------------------
int LCPI_OS__ThreadApi::ThreadWaiter::Helper__Exec(self_type* const pThis)
{
 LCPI__assert(pThis!=nullptr);
 LCPI__assert(pThis->m_hThread!=pthread_t());

 return pthread_join(pThis->m_hThread,nullptr); //no throw?
}//Helper__Exec

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi::ThreadData

class LCPI_OS__ThreadApi::ThreadData LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=ThreadData;

  ThreadData(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  ThreadData();

 private:
  friend class ThreadDataProvider;

 ~ThreadData();

 public:
  ThreadWaiter::self_ptr Get(pthread_t hThread);

  ThreadWaiter::self_ptr GetAndDel(pthread_t hThread);

 private:
  using waiters_type
   =std::map
     <pthread_t,
      ThreadWaiter::self_ptr>;

 private:
  std::mutex m_WaitersGuard;

  waiters_type m_Waiters;
};//class LCPI_OS__ThreadApi::ThreadData

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi::ThreadData

LCPI_OS__ThreadApi::ThreadData::ThreadData()
{
}//ThreadData

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::ThreadData::~ThreadData()
{
 assert_msg(ThreadWaiter::GetInstanceCount()==0,"count"<<ThreadWaiter::GetInstanceCount());

 LCPI__assert(m_Waiters.empty());
}//~ThreadData

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::ThreadWaiter::self_ptr
 LCPI_OS__ThreadApi::ThreadData::Get(pthread_t const hThread)
{
 LCPI__assert(hThread!=pthread_t());

 std::lock_guard<std::mutex> __lock(m_WaitersGuard);

 auto const x=m_Waiters.find(hThread);

 if(x!=m_Waiters.end())
 {
  LCPI__assert((*x).second);

  return (*x).second;
 }//if

 auto spNewWaiter(ThreadWaiter::Create(hThread));

 LCPI__assert(spNewWaiter);

 LCPI__VERIFY_EQ(m_Waiters.insert(std::make_pair(hThread,spNewWaiter)) LCPI__DEBUG_CODE(.second), true);

 return spNewWaiter;
}//Get

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::ThreadWaiter::self_ptr
 LCPI_OS__ThreadApi::ThreadData::GetAndDel(pthread_t const hThread)
{
 LCPI__assert(hThread!=pthread_t());

 std::lock_guard<std::mutex> __lock(m_WaitersGuard);

 auto const x=m_Waiters.find(hThread);

 if(x==m_Waiters.end())
  return nullptr;

 auto r=(*x).second;

 LCPI__assert(r);

 m_Waiters.erase(x);

 return r;
}//GetAndDel

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi::ThreadDataProvider

class LCPI_OS__ThreadApi::ThreadDataProvider LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=ThreadDataProvider;

  ThreadDataProvider(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  static self_type Instance;

 private:
  ThreadDataProvider();

 ~ThreadDataProvider();

 public:
  ThreadData* GetThreadData();

  ThreadData* GetThreadDataNoCreate();

 private:
  std::atomic<ThreadData*> m_apThreadData;
};//class LCPI_OS__ThreadApi::ThreadDataProvider

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi::ThreadDataProvider

LCPI_OS__ThreadApi::ThreadDataProvider
 LCPI_OS__ThreadApi::ThreadDataProvider::Instance;

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::ThreadDataProvider::ThreadDataProvider()
 :m_apThreadData(nullptr)
{
}//ThreadDataProvider

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::ThreadDataProvider::~ThreadDataProvider()
{
 if(auto const p=m_apThreadData.exchange(nullptr))
 {
  LCPI__assert(p!=nullptr);

  delete p;
 }//if p
}//~ThreadDataProvider

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::ThreadData* LCPI_OS__ThreadApi::ThreadDataProvider::GetThreadData()
{
 if(auto const p=m_apThreadData.load())
  return p;

 ThreadData* pExp=nullptr; //it is a result

 auto pNewData=new ThreadData();

 const auto r=m_apThreadData.compare_exchange_strong(pExp,pNewData);

 LCPI__assert(m_apThreadData.load()!=nullptr);

 LCPI__assert(m_apThreadData.load()==pNewData || m_apThreadData.load()==pExp);

 if(r)
 {
  LCPI__assert(m_apThreadData.load()==pNewData);

  LCPI__assert(pExp==nullptr);

  return pNewData;
 }

 assert_hint(!r);

 LCPI__assert(pExp!=nullptr);

 LCPI__assert(pExp!=pNewData);

 LCPI__assert(m_apThreadData.load()==pExp);

 //Rollback
 delete pNewData;

 return pExp;
}//GetThreadData

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::ThreadData* LCPI_OS__ThreadApi::ThreadDataProvider::GetThreadDataNoCreate()
{
 return m_apThreadData.load();
}//GetThreadDataNoCreate

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi - thread functions

LCPI_OS__ThreadApi::THREAD_HANDLE LCPI_OS__ThreadApi::CreateThread
                             (THREAD_ROUTINE const routine,
                              void*          const pArg)
{
 LCPI__assert(routine);

 pthread_t hThread=pthread_t();

 const int create_r
  =pthread_create
    (&hThread,
     nullptr,
     routine,
     pArg);

 if(create_r!=0)
  ErrorUtils::ThrowSystemError__CreateThread__failed(create_r);

 LCPI__assert(hThread!=pthread_t());

 return hThread;
}//CreateThread

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::WaitAndCloseThread(THREAD_HANDLE const hThread)
{
 LCPI__assert(hThread!=THREAD_HANDLE());

 for(;;)
 {
  auto const pThreadData
   =ThreadDataProvider::Instance.GetThreadDataNoCreate();

  if(!pThreadData)
   break;

  LCPI__assert(pThreadData);

  auto const spWaiter
   =pThreadData->GetAndDel(hThread);

  if(!spWaiter)
   break;

  LCPI__assert(spWaiter);

  spWaiter->FinalWait();

  return;
 }//for[ever]

 pthread_join(hThread,nullptr);
}//WaitAndCloseThread

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::WaitResultCode
 LCPI_OS__ThreadApi::WaitForSingleThread
                             (THREAD_HANDLE const hThread,
                              TimeOut_t     const milliseconds)
{
 if(hThread==THREAD_HANDLE())
 {
  ErrorUtils::ThrowBugCheckError__InvalidThreadHandle
   ("LCPI_OS__ThreadApi::WaitForSingleThread");
 }//if

 auto const pThreadData
  =ThreadDataProvider::Instance.GetThreadData();

 LCPI__assert(pThreadData);

 auto const spWaiter
  =pThreadData->Get(hThread);

 LCPI__assert(spWaiter);

 const auto threadResult
  =spWaiter->GetFutureCopy();

 if(milliseconds==self_type::Infinite)
 {
  threadResult.wait();

  return WaitResultCode::Ok;
 }//if

 const auto wait_r
  =threadResult.wait_for
    (std::chrono::milliseconds(milliseconds));

 if(wait_r==std::future_status::timeout)
  return WaitResultCode::Timeout;

 LCPI__assert(wait_r==std::future_status::ready);

 return WaitResultCode::Ok;
}//WaitForSingleThread

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi - event functions

LCPI_OS__ThreadApi::EVENT_HANDLE
 LCPI_OS__ThreadApi::CreateEvent(bool ManualReset,bool InitialState)
{
 const auto hEvent
  =EventApi::CreateEvent
    (ManualReset,
     InitialState); //throw

 LCPI__assert(hEvent!=nullptr);

 return hEvent;
}//CreateEvent

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::CloseEvent(EVENT_HANDLE const hEvent)
{
 if(hEvent==nullptr)
 {
  ErrorUtils::ThrowBugCheckError__InvalidEventHandle
   ("LCPI_OS__ThreadApi::CloseEvent");
 }//if

 LCPI__assert_hint(hEvent!=nullptr);

 return EventApi::DestroyEvent((EventApi::neosmart_event_t)hEvent);
}//CloseEvent

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::SetEvent(EVENT_HANDLE const hEvent)
{
 if(hEvent==nullptr)
 {
  ErrorUtils::ThrowBugCheckError__InvalidEventHandle
   ("LCPI_OS__ThreadApi::SetEvent");
 }//if

 LCPI__assert_hint(hEvent!=nullptr);

 return EventApi::SetEvent((EventApi::neosmart_event_t)hEvent);
}//SetEvent

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ResetEvent(EVENT_HANDLE const hEvent)
{
 if(hEvent==nullptr)
 {
  ErrorUtils::ThrowBugCheckError__InvalidEventHandle
   ("LCPI_OS__ThreadApi::ResetEvent");
 }//if

 LCPI__assert_hint(hEvent!=nullptr);

 return EventApi::ResetEvent((EventApi::neosmart_event_t)hEvent);
}//ResetEvent

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::WaitResultCode
 LCPI_OS__ThreadApi::WaitForSingleEvent(EVENT_HANDLE const hEvent,
                                        TimeOut_t    const milliseconds)
{
 const char* const c_bugcheck_src
  ="LCPI_OS__ThreadApi::WaitForSingleEvent";

 if(hEvent==nullptr)
 {
  ErrorUtils::ThrowBugCheckError__InvalidEventHandle
   (c_bugcheck_src);
 }//if

 const int wait_r
  =EventApi::WaitForEvent
    ((EventApi::neosmart_event_t)hEvent,
     milliseconds);

 switch(wait_r)
 {
  case 0:
   break;

  case ETIMEDOUT:
   return WaitResultCode::Timeout;

  default:
   ErrorUtils::ThrowBugCheckError__UnknownWaitResult
    (c_bugcheck_src,
     wait_r);
 }//switch wait_r

 return WaitResultCode::Ok;
}//WaitForSingleEvent

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::MultiWaitResult
 LCPI_OS__ThreadApi::WaitForMultipleEvents
                             (size_t              const cEvents,
                              const EVENT_HANDLE* const rghEvents,
                              bool                const waitAll,
                              TimeOut_t           const milliseconds)
{
 const char* const c_bugcheck_src
  ="LCPI_OS__ThreadApi::WaitForMultipleEvents";

 if(cEvents==0)
 {
  ErrorUtils::ThrowBugCheckError__InvalidArgumentValue
   (c_bugcheck_src,
    "cEvents",
    std::to_string(cEvents).c_str());
 }//if

 if(rghEvents==nullptr)
 {
  ErrorUtils::ThrowBugCheckError__InvalidArgumentValue
   (c_bugcheck_src,
    "rghEvents",
    "NULL");
 }//if

 size_t objectIndex=lib::structure::negative_one;

 const auto wait_r
  =EventApi::WaitForMultipleEvents
    ((const EventApi::neosmart_event_t*)rghEvents,
     cEvents,
     waitAll,
     milliseconds,
     objectIndex);

 switch(wait_r)
 {
  case 0:
   break;

  case ETIMEDOUT:
   return MultiWaitResult(WaitResultCode::Timeout,lib::structure::negative_one);

  default:
   ErrorUtils::ThrowBugCheckError__UnknownWaitResult
    (c_bugcheck_src,
     wait_r);
 }//switch wait_r

 if(cEvents<=objectIndex)
 {
  ErrorUtils::ThrowBugCheckError__WFME_Returned_Invalid_Object_Index
   (c_bugcheck_src,
    cEvents,
    objectIndex);
 }//if

 return MultiWaitResult(WaitResultCode::Ok,objectIndex);
}//WaitForMultipleEvents

////////////////////////////////////////////////////////////////////////////////

void LCPI_OS__ThreadApi::GetCurrentThreadUsageTimes
                             (TIME_DURATION* const pKernelTime,
                              TIME_DURATION* const pUserTime)
{
 LCPI__assert(pKernelTime!=nullptr);
 LCPI__assert(pUserTime!=nullptr);

 LCPI__assert(TIME_DURATION::zero()==TIME_DURATION());

 (*pKernelTime)=TIME_DURATION::zero();
 (*pUserTime)=TIME_DURATION::zero();

 struct timespec ts;

 const int r
  =clock_gettime
    (CLOCK_THREAD_CPUTIME_ID,
     &ts);

 if(r!=0)
  ErrorUtils::ThrowSystemError__clock_gettime__failed(r);

 TIME_DURATION x=std::chrono::seconds(ts.tv_sec);

 x+=std::chrono::duration_cast<TIME_DURATION>(std::chrono::nanoseconds(ts.tv_nsec));

 (*pUserTime)=x;
}//GetCurrentThreadUsageTimes

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms os*/}/*nms infrastructure*/}/*nms lcpi*/
