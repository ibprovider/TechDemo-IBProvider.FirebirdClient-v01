////////////////////////////////////////////////////////////////////////////////
//Stub-call for declarations like __closure_think

namespace closure_v3{
////////////////////////////////////////////////////////////////////////////////
//struct __closure_data

struct __closure_data
{
 public:
  void* object_ptr;

  void* buffer[4]; //SIZE IS FIXED !!!

  __closure_data()
   :object_ptr(nullptr)
  {
   this->buffer[0] =nullptr;
   this->buffer[1] =nullptr;
   this->buffer[2] =nullptr;
   this->buffer[3] =nullptr;
  }//constructor

  explicit __closure_data(void* const func)
   :object_ptr(nullptr)
  {
   this->buffer[0]=func;
   this->buffer[1]=nullptr;
   this->buffer[2]=nullptr;
   this->buffer[3]=nullptr;
  }//constructor

  __closure_data(void*       const ptr,
                 const void* const pv,
                 size_t      const sz)
   :object_ptr(ptr)
  {
   this->buffer[0]=nullptr;
   this->buffer[1]=nullptr;
   this->buffer[2]=nullptr;
   this->buffer[3]=nullptr;

   assert(sz<=sizeof(this->buffer));

   memcpy(this->buffer,pv,sz);
  }//constructor

  bool valid () const
  {
   return (this->object_ptr ||
           this->buffer[0]  ||
           this->buffer[1]  ||
           this->buffer[2]  ||
           this->buffer[3]);
  }//valid
};//__closure_data

////////////////////////////////////////////////////////////////////////////////
}//namespace closure_v3
