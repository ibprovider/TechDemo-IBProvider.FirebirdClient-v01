////////////////////////////////////////////////////////////////////////////////
//Win32 library implementation.
//                                                 Dmitry Kovalenko. 08.02.2005.

////////////////////////////////////////////////////////////////////////////////
//class TResourceCatalog

class TResourceCatalog
{
 private:
  typedef TResourceCatalog                self_type;

 public:
  typedef std::vector<TResID_Ex>          resid_vector;
  typedef t_char                          char_type;

 private:
  class TNamePushBacker;

 public:
  static BOOL EnumNames(HINSTANCE        const hInstance,
                        const char_type* const szTypes,
                        resid_vector&          Names);
};//class TResourceCatalog

////////////////////////////////////////////////////////////////////////////////
