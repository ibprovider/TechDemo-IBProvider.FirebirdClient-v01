////////////////////////////////////////////////////////////////////////////////
//BUILT-IN TEST CODE

#ifndef NDEBUG

namespace{
////////////////////////////////////////////////////////////////////////////////

class DEBUG__TEST__LCPI_OS__InterlockedFunctions LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  DEBUG__TEST__LCPI_OS__InterlockedFunctions()
  {
   DEBUG__TEST__LCPI_OS__InterlockedFunctions::Helper__Test32();
   DEBUG__TEST__LCPI_OS__InterlockedFunctions::Helper__Test64();
  }//DEBUG__TEST__LCPI_OS__InterlockedFunctions

 private:
  static void Helper__Test32()
  {
   using value_t=std::uint32_t;

   value_t v=0;

   assert(LCPI_OS__InterlockedIncrement32(&v)==1);
   assert(v==1);

   assert(LCPI_OS__InterlockedDecrement32(&v)==0);
   assert(v==0);

   assert(LCPI_OS__InterlockedExchange32(&v,123)==0);
   assert(v==123);

   assert(LCPI_OS__InterlockedExchange32(&v,321)==123);
   assert(v==321);

   assert(LCPI_OS__InterlockedCompareExchange32(&v,234,1)==321);
   assert(v==321);

   assert(LCPI_OS__InterlockedCompareExchange32(&v,234,321)==321);
   assert(v==234);

   assert(LCPI_OS__InterlockedExchangeAdd32(&v,1)==234);
   assert(v==235);

   assert(LCPI_OS__InterlockedAdd32(&v,1)==236);
   assert(v==236);
  }//Helper__Test32

  //----------------------------------------------------------------------
  static void Helper__Test64()
  {
   using value_t=std::uint64_t;

   value_t v=0;

   assert(LCPI_OS__InterlockedIncrement64(&v)==1);
   assert(v==1);

   assert(LCPI_OS__InterlockedDecrement64(&v)==0);
   assert(v==0);

   assert(LCPI_OS__InterlockedExchange64(&v,123)==0);
   assert(v==123);

   assert(LCPI_OS__InterlockedExchange64(&v,321)==123);
   assert(v==321);

   assert(LCPI_OS__InterlockedCompareExchange64(&v,234,1)==321);
   assert(v==321);

   assert(LCPI_OS__InterlockedCompareExchange64(&v,234,321)==321);
   assert(v==234);

   assert(LCPI_OS__InterlockedExchangeAdd64(&v,1)==234);
   assert(v==235);

   assert(LCPI_OS__InterlockedAdd64(&v,1)==236);
   assert(v==236);
  }//Helper__Test64
} const static __debug__TEST__LCPI_OS__InterlockedFunctions;

////////////////////////////////////////////////////////////////////////////////
}//namespace

#endif // !NDEBUG

