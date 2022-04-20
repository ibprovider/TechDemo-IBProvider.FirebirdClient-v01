////////////////////////////////////////////////////////////////////////////////
//Wrapper for resource identificator
//                                                 Dmitry Kovalenko. 19.04.2004

////////////////////////////////////////////////////////////////////////////////
//containings

template<class T>
class TResID_Wrapper;   //service class

class TResID;

class TResID_Ex;

////////////////////////////////////////////////////////////////////////////////
//Helper tips
//
// [use] os<<resID.Wrap()
//

////////////////////////////////////////////////////////////////////////////////
//class TResID_Wrapper

template<class T>
class TResID_Wrapper
{
 private:
  typedef TResID_Wrapper<T>        self_type;
 
  self_type& operator = (const self_type);
  
 public:
  const T& m_data;

  TResID_Wrapper(const T& x)
   :m_data(x)
  {;}
};//class TResID_Wrapper

////////////////////////////////////////////////////////////////////////////////
//template insert operator

template<class T,class T2>
T& operator << (T& x,const win32lib::TResID_Wrapper<T2>& w)
{
 if(w.m_data.IsString())
  x<<w.m_data.AsString();
 else
  x<<w.m_data.AsNumber();

 return x;
}//operator <<

////////////////////////////////////////////////////////////////////////////////
//class TResID

class TResID
{
 private:
  typedef TResID                            self_type;

 public: //typedefs ------------------------------------------------------
  typedef t_char                            char_type;
  typedef WORD                              id_type;

  typedef __STL_DEF_BASIC_STRING(char_type) string_type;

 public: //---------------------------------------------------------------
  TResID();

  TResID(const char_type* const resStr);

  TResID(id_type const resNum);

 public: //selectors -----------------------------------------------------
  bool IsString() const
   {return !IS_INTRESOURCE(m_Str);}

  const char_type* AsString() const
   {assert(this->IsString());return m_Str;}

  id_type AsNumber()const
   {assert(!this->IsString());return m_Num;}

  TResID_Wrapper<self_type> Wrap()const
   {return TResID_Wrapper<self_type>(*this);}

 public: //---------------------------------------------------------------

  //prevent implicit convert to text format
  operator string_type   () const;

  operator char_type* () const
   {return const_cast<char_type*>(m_Str);}

 private:
  union
  {
   id_type          m_Num;
   const char_type* m_Str;
  };
};//class TResID

////////////////////////////////////////////////////////////////////////////////
//class TResID_Ex

class TResID_Ex
{
 private:
  typedef TResID_Ex                         self_type;

 public: //typedefs ------------------------------------------------------
  typedef t_char                            char_type;
  typedef WORD                              id_type;

  typedef __STL_DEF_BASIC_STRING(char_type) string_type;

 public: //---------------------------------------------------------------
  TResID_Ex();

  TResID_Ex(const self_type&);

  TResID_Ex(const char_type* resStr);

  TResID_Ex(const id_type resNum);

 ~TResID_Ex(); 

  self_type& operator = (const self_type&);

  self_type& operator = (const char_type* const resStr);

  self_type& operator = (const id_type resNum);

  self_type& swap(self_type&);

 public: //selectors -----------------------------------------------------
  bool IsString() const
   {return !IS_INTRESOURCE(m_Str);}

  const char_type* AsString() const
   {assert(this->IsString());return m_Str;}

  id_type AsNumber()const
   {assert(!this->IsString());return m_Num;}

  TResID_Wrapper<self_type> Wrap()const
   {return TResID_Wrapper<self_type>(*this);}

 public: //---------------------------------------------------------------
  //prevent implicit convert to text format
  operator string_type () const;

  operator char_type* () const
   {return const_cast<char_type*>(m_Str);}

  operator TResID () const
   {return TResID(m_Str);}
    
 private:
  union
  {
   id_type      m_Num;
   char_type*   m_Str;
  };
};//class TResID_Ex

////////////////////////////////////////////////////////////////////////////////
//class TResID - inline implementations

inline TResID::TResID()
 :m_Str(NULL)
{;}

//------------------------------------------------------------------------
inline TResID::TResID(const char_type* const resStr)
 :m_Str(resStr)
{;}

//------------------------------------------------------------------------
inline TResID::TResID(id_type const resNum)
 :m_Str(MAKEINTRESOURCE(resNum))
{;}

////////////////////////////////////////////////////////////////////////////////
//class TResID_Ex - inline implementations

inline TResID_Ex::TResID_Ex()
 :m_Str(0)
{;}

//------------------------------------------------------------------------
inline TResID_Ex::TResID_Ex(id_type const resNum)
 :m_Str(MAKEINTRESOURCE(resNum))
{;}

////////////////////////////////////////////////////////////////////////////////
