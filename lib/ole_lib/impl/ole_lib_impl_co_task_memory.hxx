////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation. Wrappers for CoTask Memory Allocation Functions
//                                             Kovalenko Dmitry. 22.02.2010.

////////////////////////////////////////////////////////////////////////////////

void* OLE_CoTaskMemAlloc(SIZE_T sz,bool alloc_empty=false);

void OLE_CoTaskMemFree(void* pv);

////////////////////////////////////////////////////////////////////////////////

template<typename T>
void OLE_CoTaskMemFreeAndSetNULL(T* &pv)
{
 void* tmp=pv;

 pv=nullptr;

 OLE_CoTaskMemFree(tmp);
}//OLE_CoTaskMemFreeAndSetNull

////////////////////////////////////////////////////////////////////////////////

template<class T>
T* CoTaskMemAllocate2(size_t const n)
{
 assert_s(sizeof(T)>0);

 const size_t m=(structure::t_numeric_limits<size_t>::max_value()/sizeof(T));

 if(m<n)
  throw std::bad_alloc();

 return static_cast<T*>(OLE_CoTaskMemAlloc(n*sizeof(T),/*alloc_empty*/false)); //throw
}//CoTaskMemAllocate2

////////////////////////////////////////////////////////////////////////////////
//class cotask_memory_pointer

template<class T>
class cotask_memory_pointer
{
 private:
  typedef cotask_memory_pointer<T>                        self_type;

  cotask_memory_pointer(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef T                                               value_type;
  typedef T*                                              pointer_type;

 public:
  cotask_memory_pointer()
   :m_ptr(nullptr)
  {;}

  cotask_memory_pointer(pointer_type const p)
   :m_ptr(p)
  {;}

 ~cotask_memory_pointer()
  {
   OLE_CoTaskMemFreeAndSetNULL(m_ptr);
  }//~cotask_memory_pointer

  //-------------
  self_type& free()
  {
   OLE_CoTaskMemFreeAndSetNULL(m_ptr);

   return *this;
  }//free

  pointer_type release()
  {
   pointer_type const x=m_ptr;

   m_ptr=nullptr;

   return x;
  }//release

  void swap(self_type& x)
  {
   std::swap(m_ptr,x.m_ptr);
  }//swap

  void swap(pointer_type& x)
  {
   std::swap(m_ptr,x);
  }//swap

  //-------------
  const pointer_type ptr()const
  {
   return m_ptr;
  }//ptr

  pointer_type& ref_ptr()
  {
   return this->free().m_ptr;
  }//ref_ptr

  pointer_type& ref_ptr(bool free)
  {
   if(free)
    return this->free().m_ptr;

   return m_ptr;
  }//ref_ptr

 public: //operators
  operator const pointer_type () const
  {
   return m_ptr;
  }

  const pointer_type operator -> () const
  {
   assert(m_ptr!=nullptr);

   return m_ptr;
  }

  value_type& operator * () const
  {
   assert(m_ptr!=nullptr);

   return *m_ptr;
  }

  self_type& operator = (T* const p)
  {
   if(m_ptr!=p)
   {
    this->free();

    m_ptr=p;
   }

   return *this;
  }//operator = T*

 private:
  pointer_type m_ptr;
};//class cotask_memory_pointer

////////////////////////////////////////////////////////////////////////////////

#define CO_MEM_POINTER3(TYPE)               \
 ole_lib::cotask_memory_pointer<TYPE>

////////////////////////////////////////////////////////////////////////////////
