#include "simppl/serverrequestdescriptor.h"

#include "simppl/detail/constants.h"


namespace simppl
{
   
namespace ipc
{


ServerRequestDescriptor::ServerRequestDescriptor()
 : requestor_(nullptr)
 , msg_(nullptr)
{
   // NOOP
}


ServerRequestDescriptor::ServerRequestDescriptor(ServerRequestDescriptor&& rhs)
 : requestor_(rhs.requestor_)
 , msg_(rhs.msg_)
{
   rhs.clear();
}


ServerRequestDescriptor& ServerRequestDescriptor::operator=(ServerRequestDescriptor&& rhs)
{
   if (this != &rhs)
   {
      requestor_ = rhs.requestor_;
      msg_ = rhs.msg_;
            
      rhs.clear();
   }
   
   return *this;
}


ServerRequestDescriptor& ServerRequestDescriptor::set(ServerRequestBase* requestor, DBusMessage* msg)
{
   requestor_ = requestor;
   msg_ = msg;
   
   return *this;
}


void ServerRequestDescriptor::clear()
{
   set(nullptr, nullptr);
}


ServerRequestDescriptor::operator const void*() const
{
   return requestor_;
}


}   // namespace ipc

}   // namespace simppl
