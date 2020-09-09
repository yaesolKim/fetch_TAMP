// Generated by gencpp from file rosplan_knowledge_msgs/DomainOperator.msg
// DO NOT EDIT!


#ifndef ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_DOMAINOPERATOR_H
#define ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_DOMAINOPERATOR_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <rosplan_knowledge_msgs/DomainFormula.h>
#include <rosplan_knowledge_msgs/DomainFormula.h>
#include <rosplan_knowledge_msgs/DomainFormula.h>
#include <rosplan_knowledge_msgs/DomainFormula.h>
#include <rosplan_knowledge_msgs/DomainFormula.h>
#include <rosplan_knowledge_msgs/DomainAssignment.h>
#include <rosplan_knowledge_msgs/DomainAssignment.h>
#include <rosplan_knowledge_msgs/ProbabilisticEffect.h>
#include <rosplan_knowledge_msgs/DomainFormula.h>
#include <rosplan_knowledge_msgs/DomainFormula.h>
#include <rosplan_knowledge_msgs/DomainFormula.h>
#include <rosplan_knowledge_msgs/DomainFormula.h>
#include <rosplan_knowledge_msgs/DomainFormula.h>
#include <rosplan_knowledge_msgs/DomainFormula.h>
#include <rosplan_knowledge_msgs/DomainInequality.h>
#include <rosplan_knowledge_msgs/DomainInequality.h>
#include <rosplan_knowledge_msgs/DomainInequality.h>

namespace rosplan_knowledge_msgs
{
template <class ContainerAllocator>
struct DomainOperator_
{
  typedef DomainOperator_<ContainerAllocator> Type;

  DomainOperator_()
    : formula()
    , at_start_add_effects()
    , at_start_del_effects()
    , at_end_add_effects()
    , at_end_del_effects()
    , at_start_assign_effects()
    , at_end_assign_effects()
    , probabilistic_effects()
    , at_start_simple_condition()
    , over_all_simple_condition()
    , at_end_simple_condition()
    , at_start_neg_condition()
    , over_all_neg_condition()
    , at_end_neg_condition()
    , at_start_comparison()
    , at_end_comparison()
    , over_all_comparison()  {
    }
  DomainOperator_(const ContainerAllocator& _alloc)
    : formula(_alloc)
    , at_start_add_effects(_alloc)
    , at_start_del_effects(_alloc)
    , at_end_add_effects(_alloc)
    , at_end_del_effects(_alloc)
    , at_start_assign_effects(_alloc)
    , at_end_assign_effects(_alloc)
    , probabilistic_effects(_alloc)
    , at_start_simple_condition(_alloc)
    , over_all_simple_condition(_alloc)
    , at_end_simple_condition(_alloc)
    , at_start_neg_condition(_alloc)
    , over_all_neg_condition(_alloc)
    , at_end_neg_condition(_alloc)
    , at_start_comparison(_alloc)
    , at_end_comparison(_alloc)
    , over_all_comparison(_alloc)  {
  (void)_alloc;
    }



   typedef  ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator>  _formula_type;
  _formula_type formula;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::other >  _at_start_add_effects_type;
  _at_start_add_effects_type at_start_add_effects;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::other >  _at_start_del_effects_type;
  _at_start_del_effects_type at_start_del_effects;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::other >  _at_end_add_effects_type;
  _at_end_add_effects_type at_end_add_effects;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::other >  _at_end_del_effects_type;
  _at_end_del_effects_type at_end_del_effects;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainAssignment_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainAssignment_<ContainerAllocator> >::other >  _at_start_assign_effects_type;
  _at_start_assign_effects_type at_start_assign_effects;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainAssignment_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainAssignment_<ContainerAllocator> >::other >  _at_end_assign_effects_type;
  _at_end_assign_effects_type at_end_assign_effects;

   typedef std::vector< ::rosplan_knowledge_msgs::ProbabilisticEffect_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::ProbabilisticEffect_<ContainerAllocator> >::other >  _probabilistic_effects_type;
  _probabilistic_effects_type probabilistic_effects;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::other >  _at_start_simple_condition_type;
  _at_start_simple_condition_type at_start_simple_condition;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::other >  _over_all_simple_condition_type;
  _over_all_simple_condition_type over_all_simple_condition;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::other >  _at_end_simple_condition_type;
  _at_end_simple_condition_type at_end_simple_condition;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::other >  _at_start_neg_condition_type;
  _at_start_neg_condition_type at_start_neg_condition;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::other >  _over_all_neg_condition_type;
  _over_all_neg_condition_type over_all_neg_condition;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::other >  _at_end_neg_condition_type;
  _at_end_neg_condition_type at_end_neg_condition;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainInequality_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainInequality_<ContainerAllocator> >::other >  _at_start_comparison_type;
  _at_start_comparison_type at_start_comparison;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainInequality_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainInequality_<ContainerAllocator> >::other >  _at_end_comparison_type;
  _at_end_comparison_type at_end_comparison;

   typedef std::vector< ::rosplan_knowledge_msgs::DomainInequality_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosplan_knowledge_msgs::DomainInequality_<ContainerAllocator> >::other >  _over_all_comparison_type;
  _over_all_comparison_type over_all_comparison;





  typedef boost::shared_ptr< ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> const> ConstPtr;

}; // struct DomainOperator_

typedef ::rosplan_knowledge_msgs::DomainOperator_<std::allocator<void> > DomainOperator;

typedef boost::shared_ptr< ::rosplan_knowledge_msgs::DomainOperator > DomainOperatorPtr;
typedef boost::shared_ptr< ::rosplan_knowledge_msgs::DomainOperator const> DomainOperatorConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator1> & lhs, const ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator2> & rhs)
{
  return lhs.formula == rhs.formula &&
    lhs.at_start_add_effects == rhs.at_start_add_effects &&
    lhs.at_start_del_effects == rhs.at_start_del_effects &&
    lhs.at_end_add_effects == rhs.at_end_add_effects &&
    lhs.at_end_del_effects == rhs.at_end_del_effects &&
    lhs.at_start_assign_effects == rhs.at_start_assign_effects &&
    lhs.at_end_assign_effects == rhs.at_end_assign_effects &&
    lhs.probabilistic_effects == rhs.probabilistic_effects &&
    lhs.at_start_simple_condition == rhs.at_start_simple_condition &&
    lhs.over_all_simple_condition == rhs.over_all_simple_condition &&
    lhs.at_end_simple_condition == rhs.at_end_simple_condition &&
    lhs.at_start_neg_condition == rhs.at_start_neg_condition &&
    lhs.over_all_neg_condition == rhs.over_all_neg_condition &&
    lhs.at_end_neg_condition == rhs.at_end_neg_condition &&
    lhs.at_start_comparison == rhs.at_start_comparison &&
    lhs.at_end_comparison == rhs.at_end_comparison &&
    lhs.over_all_comparison == rhs.over_all_comparison;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator1> & lhs, const ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace rosplan_knowledge_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> >
{
  static const char* value()
  {
    return "169396bd4c8278ca06550ef5a062c243";
  }

  static const char* value(const ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x169396bd4c8278caULL;
  static const uint64_t static_value2 = 0x06550ef5a062c243ULL;
};

template<class ContainerAllocator>
struct DataType< ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rosplan_knowledge_msgs/DomainOperator";
  }

  static const char* value(const ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# A message used to represent an ungrounded operator in the domain.\n"
"\n"
"# (1) name and parameters\n"
"rosplan_knowledge_msgs/DomainFormula formula\n"
"\n"
"# (2) duration constraint\n"
"\n"
"\n"
"# (3) effect lists\n"
"rosplan_knowledge_msgs/DomainFormula[] at_start_add_effects\n"
"rosplan_knowledge_msgs/DomainFormula[] at_start_del_effects\n"
"rosplan_knowledge_msgs/DomainFormula[] at_end_add_effects\n"
"rosplan_knowledge_msgs/DomainFormula[] at_end_del_effects\n"
"rosplan_knowledge_msgs/DomainAssignment[] at_start_assign_effects\n"
"rosplan_knowledge_msgs/DomainAssignment[] at_end_assign_effects\n"
"rosplan_knowledge_msgs/ProbabilisticEffect[] probabilistic_effects\n"
"\n"
"# (4) conditions\n"
"rosplan_knowledge_msgs/DomainFormula[] at_start_simple_condition\n"
"rosplan_knowledge_msgs/DomainFormula[] over_all_simple_condition\n"
"rosplan_knowledge_msgs/DomainFormula[] at_end_simple_condition\n"
"rosplan_knowledge_msgs/DomainFormula[] at_start_neg_condition\n"
"rosplan_knowledge_msgs/DomainFormula[] over_all_neg_condition\n"
"rosplan_knowledge_msgs/DomainFormula[] at_end_neg_condition\n"
"rosplan_knowledge_msgs/DomainInequality[] at_start_comparison\n"
"rosplan_knowledge_msgs/DomainInequality[] at_end_comparison\n"
"rosplan_knowledge_msgs/DomainInequality[] over_all_comparison\n"
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
"\n"
"================================================================================\n"
"MSG: rosplan_knowledge_msgs/DomainAssignment\n"
"# A message used to store the numeric effects of an action\n"
"# Can be grounded or ungrounded\n"
"\n"
"uint8 ASSIGN   = 0\n"
"uint8 INCREASE  = 1\n"
"uint8 DECREASE = 2\n"
"uint8 SCALE_UP = 3\n"
"uint8 SCALE_DOWN = 4\n"
"uint8 ASSIGN_CTS = 5\n"
"\n"
"uint8 assign_type\n"
"\n"
"rosplan_knowledge_msgs/DomainFormula LHS\n"
"rosplan_knowledge_msgs/ExprComposite RHS\n"
"\n"
"bool grounded\n"
"\n"
"================================================================================\n"
"MSG: rosplan_knowledge_msgs/ExprComposite\n"
"# A message used to represent a numerical expression; composite type (2/2)\n"
"# stores an array of ExprBase as prefix notation\n"
"\n"
"# components\n"
"ExprBase[] tokens\n"
"\n"
"================================================================================\n"
"MSG: rosplan_knowledge_msgs/ExprBase\n"
"# A message used to represent a numerical expression; base types (1/2)\n"
"\n"
"# expression types\n"
"uint8 CONSTANT = 0\n"
"uint8 FUNCTION = 1\n"
"uint8 OPERATOR = 2\n"
"uint8 SPECIAL  = 3\n"
"\n"
"# operators\n"
"uint8 ADD    = 0\n"
"uint8 SUB    = 1\n"
"uint8 MUL    = 2\n"
"uint8 DIV    = 3\n"
"uint8 UMINUS = 4\n"
"\n"
"# special types\n"
"uint8 HASHT      = 0\n"
"uint8 TOTAL_TIME = 1\n"
"uint8 DURATION   = 2\n"
"\n"
"# expression base type\n"
"uint8 expr_type\n"
"\n"
"# constant value\n"
"float64 constant\n"
"\n"
"# function\n"
"rosplan_knowledge_msgs/DomainFormula function\n"
"\n"
"# operator\n"
"uint8 op\n"
"\n"
"# special\n"
"uint8 special_type\n"
"\n"
"================================================================================\n"
"MSG: rosplan_knowledge_msgs/ProbabilisticEffect\n"
"# Message used to represent a Probabilistic effect \n"
"rosplan_knowledge_msgs/ExprComposite   probability\n"
"rosplan_knowledge_msgs/DomainFormula[] add_effects # Add effects\n"
"rosplan_knowledge_msgs/DomainFormula[] del_effects # Del effects\n"
"rosplan_knowledge_msgs/DomainAssignment[] assign_effects # Assign effects, mainly used for RDDL Discrete distribution\n"
"================================================================================\n"
"MSG: rosplan_knowledge_msgs/DomainInequality\n"
"# A message used to store the numeric effects of an action\n"
"# Can be grounded or ungrounded\n"
"\n"
"uint8 GREATER   = 0\n"
"uint8 GREATEREQ = 1\n"
"uint8 LESS      = 2\n"
"uint8 LESSEQ    = 3\n"
"uint8 EQUALS    = 4\n"
"\n"
"uint8 comparison_type\n"
"\n"
"rosplan_knowledge_msgs/ExprComposite LHS\n"
"rosplan_knowledge_msgs/ExprComposite RHS\n"
"\n"
"bool grounded\n"
;
  }

  static const char* value(const ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.formula);
      stream.next(m.at_start_add_effects);
      stream.next(m.at_start_del_effects);
      stream.next(m.at_end_add_effects);
      stream.next(m.at_end_del_effects);
      stream.next(m.at_start_assign_effects);
      stream.next(m.at_end_assign_effects);
      stream.next(m.probabilistic_effects);
      stream.next(m.at_start_simple_condition);
      stream.next(m.over_all_simple_condition);
      stream.next(m.at_end_simple_condition);
      stream.next(m.at_start_neg_condition);
      stream.next(m.over_all_neg_condition);
      stream.next(m.at_end_neg_condition);
      stream.next(m.at_start_comparison);
      stream.next(m.at_end_comparison);
      stream.next(m.over_all_comparison);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DomainOperator_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rosplan_knowledge_msgs::DomainOperator_<ContainerAllocator>& v)
  {
    s << indent << "formula: ";
    s << std::endl;
    Printer< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::stream(s, indent + "  ", v.formula);
    s << indent << "at_start_add_effects[]" << std::endl;
    for (size_t i = 0; i < v.at_start_add_effects.size(); ++i)
    {
      s << indent << "  at_start_add_effects[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::stream(s, indent + "    ", v.at_start_add_effects[i]);
    }
    s << indent << "at_start_del_effects[]" << std::endl;
    for (size_t i = 0; i < v.at_start_del_effects.size(); ++i)
    {
      s << indent << "  at_start_del_effects[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::stream(s, indent + "    ", v.at_start_del_effects[i]);
    }
    s << indent << "at_end_add_effects[]" << std::endl;
    for (size_t i = 0; i < v.at_end_add_effects.size(); ++i)
    {
      s << indent << "  at_end_add_effects[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::stream(s, indent + "    ", v.at_end_add_effects[i]);
    }
    s << indent << "at_end_del_effects[]" << std::endl;
    for (size_t i = 0; i < v.at_end_del_effects.size(); ++i)
    {
      s << indent << "  at_end_del_effects[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::stream(s, indent + "    ", v.at_end_del_effects[i]);
    }
    s << indent << "at_start_assign_effects[]" << std::endl;
    for (size_t i = 0; i < v.at_start_assign_effects.size(); ++i)
    {
      s << indent << "  at_start_assign_effects[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainAssignment_<ContainerAllocator> >::stream(s, indent + "    ", v.at_start_assign_effects[i]);
    }
    s << indent << "at_end_assign_effects[]" << std::endl;
    for (size_t i = 0; i < v.at_end_assign_effects.size(); ++i)
    {
      s << indent << "  at_end_assign_effects[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainAssignment_<ContainerAllocator> >::stream(s, indent + "    ", v.at_end_assign_effects[i]);
    }
    s << indent << "probabilistic_effects[]" << std::endl;
    for (size_t i = 0; i < v.probabilistic_effects.size(); ++i)
    {
      s << indent << "  probabilistic_effects[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::ProbabilisticEffect_<ContainerAllocator> >::stream(s, indent + "    ", v.probabilistic_effects[i]);
    }
    s << indent << "at_start_simple_condition[]" << std::endl;
    for (size_t i = 0; i < v.at_start_simple_condition.size(); ++i)
    {
      s << indent << "  at_start_simple_condition[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::stream(s, indent + "    ", v.at_start_simple_condition[i]);
    }
    s << indent << "over_all_simple_condition[]" << std::endl;
    for (size_t i = 0; i < v.over_all_simple_condition.size(); ++i)
    {
      s << indent << "  over_all_simple_condition[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::stream(s, indent + "    ", v.over_all_simple_condition[i]);
    }
    s << indent << "at_end_simple_condition[]" << std::endl;
    for (size_t i = 0; i < v.at_end_simple_condition.size(); ++i)
    {
      s << indent << "  at_end_simple_condition[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::stream(s, indent + "    ", v.at_end_simple_condition[i]);
    }
    s << indent << "at_start_neg_condition[]" << std::endl;
    for (size_t i = 0; i < v.at_start_neg_condition.size(); ++i)
    {
      s << indent << "  at_start_neg_condition[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::stream(s, indent + "    ", v.at_start_neg_condition[i]);
    }
    s << indent << "over_all_neg_condition[]" << std::endl;
    for (size_t i = 0; i < v.over_all_neg_condition.size(); ++i)
    {
      s << indent << "  over_all_neg_condition[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::stream(s, indent + "    ", v.over_all_neg_condition[i]);
    }
    s << indent << "at_end_neg_condition[]" << std::endl;
    for (size_t i = 0; i < v.at_end_neg_condition.size(); ++i)
    {
      s << indent << "  at_end_neg_condition[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainFormula_<ContainerAllocator> >::stream(s, indent + "    ", v.at_end_neg_condition[i]);
    }
    s << indent << "at_start_comparison[]" << std::endl;
    for (size_t i = 0; i < v.at_start_comparison.size(); ++i)
    {
      s << indent << "  at_start_comparison[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainInequality_<ContainerAllocator> >::stream(s, indent + "    ", v.at_start_comparison[i]);
    }
    s << indent << "at_end_comparison[]" << std::endl;
    for (size_t i = 0; i < v.at_end_comparison.size(); ++i)
    {
      s << indent << "  at_end_comparison[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainInequality_<ContainerAllocator> >::stream(s, indent + "    ", v.at_end_comparison[i]);
    }
    s << indent << "over_all_comparison[]" << std::endl;
    for (size_t i = 0; i < v.over_all_comparison.size(); ++i)
    {
      s << indent << "  over_all_comparison[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosplan_knowledge_msgs::DomainInequality_<ContainerAllocator> >::stream(s, indent + "    ", v.over_all_comparison[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_DOMAINOPERATOR_H
