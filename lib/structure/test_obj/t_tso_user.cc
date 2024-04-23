////////////////////////////////////////////////////////////////////////////////
#ifndef _t_tso_user_CC_
#define _t_tso_user_CC_

namespace structure{namespace tso_obj{
////////////////////////////////////////////////////////////////////////////////
//run_tests

template<class tag_test_descr,class tag_test_arg>
int run_tests(const tag_test_descr* pTests,const tag_test_arg& Arg)
{
 if(pTests==nullptr)
  return 0;
 
 int error_count=0;

 for(;pTests->func!=nullptr;++pTests)
 {
  assert(pTests->name);

  _TSO_TRY_
  {
   std::cout<<std::endl;
   std::cout<<"------------------------------------------"<<std::endl;
   std::cout<<"RUN: ["<<pTests->name<<"]"<<std::endl;

   pTests->func(Arg);

   std::cout<<std::endl;
  }
  _TSO_CATCHES_("run_tests",error_count)
 }//for i

 return error_count;
}//run_tests

////////////////////////////////////////////////////////////////////////////////
}/*nms tso_obj*/}/*nms structure*/
#endif                 
