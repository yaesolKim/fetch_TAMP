// Generated by gencpp from file rosplan_knowledge_msgs/GetDomainOperatorServiceResponse.msg
// DO NOT EDIT!


#ifndef ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_GETDOMAINOPERATORSERVICERESPONSE_H
#define ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_GETDOMAINOPERATORSERVICERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <rosplan_knowledge_msgs/DomainFormula.h>

namespace rosplan_knowledge_msgs
{
template <class ContainerAllocator>
struct GetDomainOperatorServiceResponse_
{
  typedef GetDomainOperatorServiceResponse_<ContainerAllocator> Type;

  GetDomainOperatorServiceResponse_()
    : operators()  {
    }
  GetDomainOperatorServiceResponse_(const ContainerAllocator& _alloc)
    : operators(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::other >  _operators_type;
  _operators_type operators;





  typedef boost::shared_ptr< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetDomainOperatorServiceResponse_

typedef ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<std::allocator<void> > GetDomainOperatorServiceResponse;

typedef boost::shared_ptr< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse > GetDomainOperatorServiceResponsePtr;
typedef boost::shared_ptr< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse const> GetDomainOperatorServiceResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator1> & lhs, const ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator2> & rhs)
{
  return lhs.operators == rhs.operators;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator1> & lhs, const ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace rosplan_knowledge_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "01315931b687093b9f4ca53107f02d57";
  }

  static const char* value(const ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x01315931b687093bULL;
  static const uint64_t static_value2 = 0x9f4ca53107f02d57ULL;
};

template<class ContainerAllocator>
struct DataType< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rosplan_knowledge_msgs/GetDomainOperatorServiceResponse";
  }

  static const char* value(const ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rosplan_knowledge_msgs/DomainFormula[] operators\n"
"\n"
"\n"
"================================================================================\n"
"MSG: rosplan_knowledge_msgs/DomainFormula\n"
"# A message used to represent an atomic formula from the domain.\n"
"# typed_parameters matches label -> type\n"
"string name\n"
"diagnostic_msgs/KeyValue[] typed_parameters\n"
"\n"
"================================================================================\n"
"MSG: diagnostic_msgs/KeyValue\n"
"string key # what to label this value when viewing\n"
"string value # a value to track over time\n"
;
  }

  static const char* value(const ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.operators);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetDomainOperatorServiceResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rosplan_knowledge_msgs::GetDomainOperatorServiceResponse_<ContainerAllocator>& v)
  {
    s << indent << "operators[]" << std::endl;
    for (size_t i = 0; i < v.operators.size(); ++i)
    {
      s << indent << "  operators[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::stream(s, indent + "    ", v.operators[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_GETDOMAINOPERATORSERVICERESPONSE_H
