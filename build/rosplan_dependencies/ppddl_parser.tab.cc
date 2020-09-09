/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         PPDDL_STYPE
/* Substitute the variable and function names.  */
#define yyparse         ppddl_parse
#define yylex           ppddl_lex
#define yyerror         ppddl_error
#define yydebug         ppddl_debug
#define yynerrs         ppddl_nerrs

#define yylval          ppddl_lval
#define yychar          ppddl_char

/* Copy the first part of user declarations.  */
#line 24 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:339  */

//#include <config.h>
#include "problems.h"
#include "domains.h"
#include "actions.h"
#include "effects.h"
#include "formulas.h"
#include "expressions.h"
#include "functions.h"
#include "predicates.h"
#include "terms.h"
#include "types.h"
#include "rational.h"
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <typeinfo>

using namespace ppddl_parser; // To avoid namespacing everything

/* Workaround for bug in Bison 1.35 that disables stack growth. */
#define YYLTYPE_IS_TRIVIAL 1

#define PACKAGE "mdpsim-ppddl-parser"

/*
 * Context of free variables.
 */
struct Context {
  void push_frame() {
    frames_.push_back(VariableMap());
  }

  void pop_frame() {
    frames_.pop_back();
  }

  void insert(const std::string& name, const Variable& v) {
    frames_.back().insert(std::make_pair(name, v));
  }

  const Variable* shallow_find(const std::string& name) const {
    VariableMap::const_iterator vi = frames_.back().find(name);
    if (vi != frames_.back().end()) {
      return &(*vi).second;
    } else {
      return 0;
    }
  }

  const Variable* find(const std::string& name) const {
    for (std::vector<VariableMap>::const_reverse_iterator fi =
           frames_.rbegin(); fi != frames_.rend(); fi++) {
      VariableMap::const_iterator vi = (*fi).find(name);
      if (vi != (*fi).end()) {
        return &(*vi).second;
      }
    }
    return 0;
  }

private:
  struct VariableMap : public std::map<std::string, Variable> {
  };

  std::vector<VariableMap> frames_;
};


/* The lexer. */
extern "C" int yylex();
/* Current line number. */
extern size_t line_number;
/* Name of current file. */
extern std::string current_file;
/* Level of warnings. */
extern int warning_level;

/* Whether the last parsing attempt succeeded. */
static bool success = true;
/* Current domain. */
static Domain* domain;
/* Domains. */
static std::map<std::string, Domain*> domains;
/* Pointer to problem being parsed, or 0 if no problem is being parsed. */
static Problem* problem;
/* Current requirements. */
static Requirements* requirements;
/* The reward function, if rewards are required. */
static Function reward_function(-1);
/* Predicate being parsed. */
static const Predicate* predicate;
/* Whether predicate declaration is repeated. */
static bool repeated_predicate;
/* Function being parsed. */
static const Function* function;
/* Whether function declaration is repeated. */
static bool repeated_function;
/* Pointer to action being parsed, or 0 if no action is being parsed. */
static ActionSchema* action;
/* Current variable context. */
static Context context;
/* Predicate for atomic state formula being parsed. */
static const Predicate* atom_predicate;
/* Whether the predicate of the currently parsed atom was undeclared. */
static bool undeclared_atom_predicate;
/* Whether parsing effect fluents. */
static bool effect_fluent;
/* Whether parsing metric fluent. */
static bool metric_fluent;
/* Function for fluent being parsed. */
static const Function* fluent_function;
/* Whether the function of the currently parsed fluent was undeclared. */
static bool undeclared_fluent_function;
/* Paramerers for atomic state formula or fluent being parsed. */
static TermList term_parameters;
/* Quantified variables for effect or formula being parsed. */
static TermList quantified;
/* Most recently parsed term for equality formula. */
static Term eq_term(0);
/* Most recently parsed expression for equality formula. */
static const Expression* eq_expr;
/* The first term for equality formula. */
static Term first_eq_term(0);
/* The first expression for equality formula. */
static const Expression* first_eq_expr;
/* Kind of name map being parsed. */
static enum { TYPE_KIND, CONSTANT_KIND, OBJECT_KIND, VOID_KIND } name_kind;

/* Outputs an error message. */
static void yyerror(const std::string& s);
/* Outputs a warning message. */
static void yywarning(const std::string& s);
/* Creates an empty domain with the given name. */
static void make_domain(const std::string* name);
/* Creates an empty problem with the given name. */
static void make_problem(const std::string* name,
                         const std::string* domain_name);
/* Adds :typing to the requirements. */
static void require_typing();
/* Adds :fluents to the requirements. */
static void require_fluents();
/* Adds :disjunctive-preconditions to the requirements. */
static void require_disjunction();
/* Adds :conditional-effects to the requirements. */
static void require_conditional_effects();
/* Returns a simple type with the given name. */
static const Type& make_type(const std::string* name);
/* Returns the union of the given types. */
static Type make_type(const TypeSet& types);
/* Returns a simple term with the given name. */
static Term make_term(const std::string* name);
/* Creates a predicate with the given name. */
static void make_predicate(const std::string* name);
/* Creates a function with the given name. */
static void make_function(const std::string* name);
/* Creates an action with the given name. */
static void make_action(const std::string* name);
/* Adds the current action to the current domain. */
static void add_action();
/* Prepares for the parsing of a universally quantified effect. */
static void prepare_forall_effect();
/* Creates a universally quantified effect. */
static const Effect* make_forall_effect(const Effect& effect);
/* Adds an outcome to the given probabilistic effect. */
static void add_outcome(std::vector<std::pair<Rational, const Effect*> >& os,
                        const Rational* p, const Effect& effect);
/* Creates a probabilistic effect. */
static const Effect*
make_prob_effect(const std::vector<std::pair<Rational, const Effect*> >* os);
/* Creates an add effect. */
static const Effect* make_add_effect(const Atom& atom);
/* Creates a delete effect. */
static const Effect* make_delete_effect(const Atom& atom);
/* Creates an assign update effect. */
static const Effect* make_assign_effect(const Fluent& fluent,
                                        const Expression& expr);
/* Creates a scale-up update effect. */
static const Effect* make_scale_up_effect(const Fluent& fluent,
                                          const Expression& expr);
/* Creates a scale-down update effect. */
static const Effect* make_scale_down_effect(const Fluent& fluent,
                                            const Expression& expr);
/* Creates an increase update effect. */
static const Effect* make_increase_effect(const Fluent& fluent,
                                          const Expression& expr);
/* Creates a decrease update effect. */
static const Effect* make_decrease_effect(const Fluent& fluent,
                                          const Expression& expr);
/* Adds types, constants, or objects to the current domain or problem. */
static void add_names(const std::vector<const std::string*>* names,
                      const Type& type);
/* Adds variables to the current variable list. */
static void add_variables(const std::vector<const std::string*>* names,
                          const Type& type);
/* Prepares for the parsing of an atomic state formula. */
static void prepare_atom(const std::string* name);
/* Prepares for the parsing of a fluent. */
static void prepare_fluent(const std::string* name);
/* Adds a term with the given name to the current atomic state formula. */
static void add_term(const std::string* name);
/* Creates the atomic formula just parsed. */
static const Atom* make_atom();
/* Creates the fluent just parsed. */
static const Fluent* make_fluent();
/* Creates a subtraction. */
static const Expression* make_subtraction(const Expression& term,
                                          const Expression* opt_term);
/* Creates an atom or fluent for the given name to be used in an
   equality formula. */
static void make_eq_name(const std::string* name);
/* Creates an equality formula. */
static const StateFormula* make_equality();
/* Creates a negated formula. */
static const StateFormula* make_negation(const StateFormula& negand);
/* Creates an implication. */
static const StateFormula* make_implication(const StateFormula& f1,
                                            const StateFormula& f2);
/* Prepares for the parsing of an existentially quantified formula. */
static void prepare_exists();
/* Prepares for the parsing of a universally quantified formula. */
static void prepare_forall();
/* Creates an existentially quantified formula. */
static const StateFormula* make_exists(const StateFormula& body);
/* Creates a universally quantified formula. */
static const StateFormula* make_forall(const StateFormula& body);
/* Sets the goal reward for the current problem. */
static void set_goal_reward(const Expression& goal_reward);
/* Sets the default metric for the current problem. */
static void set_default_metric();

#line 308 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "ppddl_parser.tab.hh".  */
#ifndef YY_PPDDL_HOME_GLAB_FETCH_TAMP_BUILD_ROSPLAN_DEPENDENCIES_PPDDL_PARSER_TAB_HH_INCLUDED
# define YY_PPDDL_HOME_GLAB_FETCH_TAMP_BUILD_ROSPLAN_DEPENDENCIES_PPDDL_PARSER_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef PPDDL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define PPDDL_DEBUG 1
#  else
#   define PPDDL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define PPDDL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined PPDDL_DEBUG */
#if PPDDL_DEBUG
extern int ppddl_debug;
#endif

/* Token type.  */
#ifndef PPDDL_TOKENTYPE
# define PPDDL_TOKENTYPE
  enum ppddl_tokentype
  {
    DEFINE = 258,
    DOMAIN_TOKEN = 259,
    PROBLEM = 260,
    REQUIREMENTS = 261,
    TYPES = 262,
    CONSTANTS = 263,
    PREDICATES = 264,
    FUNCTIONS = 265,
    STRIPS = 266,
    TYPING = 267,
    NEGATIVE_PRECONDITIONS = 268,
    DISJUNCTIVE_PRECONDITIONS = 269,
    EQUALITY = 270,
    EXISTENTIAL_PRECONDITIONS = 271,
    UNIVERSAL_PRECONDITIONS = 272,
    QUANTIFIED_PRECONDITIONS = 273,
    CONDITIONAL_EFFECTS = 274,
    FLUENTS = 275,
    ADL = 276,
    DURATIVE_ACTIONS = 277,
    DURATION_INEQUALITIES = 278,
    CONTINUOUS_EFFECTS = 279,
    PROBABILISTIC_EFFECTS = 280,
    REWARDS = 281,
    MDP = 282,
    ACTION = 283,
    PARAMETERS = 284,
    PRECONDITION = 285,
    EFFECT = 286,
    PDOMAIN = 287,
    OBJECTS = 288,
    INIT = 289,
    GOAL = 290,
    GOAL_REWARD = 291,
    METRIC = 292,
    TOTAL_TIME = 293,
    GOAL_ACHIEVED = 294,
    WHEN = 295,
    NOT = 296,
    AND = 297,
    OR = 298,
    IMPLY = 299,
    EXISTS = 300,
    FORALL = 301,
    PROBABILISTIC = 302,
    ASSIGN = 303,
    SCALE_UP = 304,
    SCALE_DOWN = 305,
    INCREASE = 306,
    DECREASE = 307,
    MINIMIZE = 308,
    MAXIMIZE = 309,
    NUMBER_TOKEN = 310,
    OBJECT_TOKEN = 311,
    EITHER = 312,
    LE = 313,
    GE = 314,
    NAME = 315,
    VARIABLE = 316,
    NUMBER = 317,
    ILLEGAL_TOKEN = 318
  };
#endif

/* Value type.  */
#if ! defined PPDDL_STYPE && ! defined PPDDL_STYPE_IS_DECLARED

union PPDDL_STYPE
{
#line 272 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:355  */

  const ppddl_parser::Effect* effect;
  std::vector<std::pair<ppddl_parser::Rational, const ppddl_parser::Effect*> >* outcomes;
  const ppddl_parser::StateFormula* formula;
  const ppddl_parser::Atom* atom;
  const ppddl_parser::Expression* expr;
  const ppddl_parser::Fluent* fluent;
  const ppddl_parser::Type* type;
  ppddl_parser::TypeSet* types;
  const std::string* str;
  std::vector<const std::string*>* strs;
  const ppddl_parser::Rational* num;

#line 434 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:355  */
};

typedef union PPDDL_STYPE PPDDL_STYPE;
# define PPDDL_STYPE_IS_TRIVIAL 1
# define PPDDL_STYPE_IS_DECLARED 1
#endif


extern PPDDL_STYPE ppddl_lval;

int ppddl_parse (void);

#endif /* !YY_PPDDL_HOME_GLAB_FETCH_TAMP_BUILD_ROSPLAN_DEPENDENCIES_PPDDL_PARSER_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 451 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined PPDDL_STYPE_IS_TRIVIAL && PPDDL_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  143
/* YYNRULES -- Number of rules.  */
#define YYNRULES  308
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  511

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      64,    65,    71,    70,     2,    66,     2,    72,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      68,    67,    69,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if PPDDL_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   305,   305,   305,   309,   310,   311,   318,   318,   322,
     323,   324,   325,   328,   329,   330,   333,   334,   335,   336,
     337,   338,   339,   342,   343,   344,   345,   346,   349,   350,
     351,   352,   353,   356,   357,   358,   359,   360,   363,   364,
     365,   368,   369,   370,   373,   374,   375,   378,   379,   382,
     385,   388,   389,   392,   393,   394,   396,   398,   399,   401,
     403,   405,   406,   407,   408,   413,   418,   423,   427,   432,
     439,   439,   443,   443,   447,   450,   450,   457,   458,   461,
     461,   465,   466,   467,   470,   471,   474,   474,   477,   477,
     485,   485,   489,   490,   493,   494,   497,   498,   501,   504,
     511,   512,   513,   513,   515,   515,   517,   521,   522,   525,
     530,   534,   537,   538,   539,   539,   541,   541,   543,   543,
     545,   545,   547,   547,   556,   555,   560,   561,   564,   565,
     568,   569,   572,   572,   576,   579,   580,   583,   584,   586,
     590,   595,   599,   600,   603,   604,   607,   608,   612,   615,
     616,   619,   620,   624,   625,   625,   627,   627,   634,   636,
     635,   638,   638,   640,   640,   642,   642,   644,   644,   646,
     647,   648,   648,   649,   650,   650,   652,   652,   656,   657,
     660,   661,   664,   664,   666,   669,   669,   671,   678,   679,
     680,   681,   682,   683,   686,   688,   688,   690,   690,   692,
     692,   694,   694,   696,   696,   698,   699,   702,   703,   706,
     706,   707,   710,   711,   713,   715,   717,   719,   720,   722,
     724,   726,   730,   731,   734,   734,   736,   743,   744,   745,
     748,   749,   752,   753,   754,   754,   758,   759,   762,   763,
     764,   764,   767,   768,   771,   771,   774,   775,   776,   779,
     780,   781,   782,   785,   792,   795,   798,   801,   804,   807,
     810,   813,   816,   819,   822,   825,   828,   831,   834,   837,
     840,   843,   846,   849,   852,   855,   855,   855,   856,   857,
     857,   858,   861,   862,   862,   865,   868,   868,   868,   869,
     869,   869,   870,   870,   870,   870,   870,   870,   870,   870,
     871,   871,   871,   871,   871,   872,   872,   873,   876
};
#endif

#if PPDDL_DEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEFINE", "DOMAIN_TOKEN", "PROBLEM",
  "REQUIREMENTS", "TYPES", "CONSTANTS", "PREDICATES", "FUNCTIONS",
  "STRIPS", "TYPING", "NEGATIVE_PRECONDITIONS",
  "DISJUNCTIVE_PRECONDITIONS", "EQUALITY", "EXISTENTIAL_PRECONDITIONS",
  "UNIVERSAL_PRECONDITIONS", "QUANTIFIED_PRECONDITIONS",
  "CONDITIONAL_EFFECTS", "FLUENTS", "ADL", "DURATIVE_ACTIONS",
  "DURATION_INEQUALITIES", "CONTINUOUS_EFFECTS", "PROBABILISTIC_EFFECTS",
  "REWARDS", "MDP", "ACTION", "PARAMETERS", "PRECONDITION", "EFFECT",
  "PDOMAIN", "OBJECTS", "INIT", "GOAL", "GOAL_REWARD", "METRIC",
  "TOTAL_TIME", "GOAL_ACHIEVED", "WHEN", "NOT", "AND", "OR", "IMPLY",
  "EXISTS", "FORALL", "PROBABILISTIC", "ASSIGN", "SCALE_UP", "SCALE_DOWN",
  "INCREASE", "DECREASE", "MINIMIZE", "MAXIMIZE", "NUMBER_TOKEN",
  "OBJECT_TOKEN", "EITHER", "LE", "GE", "NAME", "VARIABLE", "NUMBER",
  "ILLEGAL_TOKEN", "'('", "')'", "'-'", "'='", "'<'", "'>'", "'+'", "'*'",
  "'/'", "$accept", "file", "$@1", "domains_and_problems", "domain_def",
  "$@2", "domain_body", "domain_body2", "domain_body3", "domain_body4",
  "domain_body5", "domain_body6", "domain_body7", "domain_body8",
  "domain_body9", "structure_defs", "structure_def", "require_def",
  "require_keys", "require_key", "types_def", "$@3", "constants_def",
  "$@4", "predicates_def", "functions_def", "$@5", "predicate_decls",
  "predicate_decl", "$@6", "function_decls", "function_decl_seq",
  "function_type_spec", "$@7", "function_decl", "$@8", "action_def", "$@9",
  "parameters", "action_body", "action_body2", "precondition", "effect",
  "eff_formula", "$@10", "$@11", "eff_formulas", "prob_effs",
  "probability", "p_effect", "$@12", "$@13", "$@14", "$@15", "$@16",
  "problem_def", "$@17", "problem_body", "problem_body2", "problem_body3",
  "object_decl", "$@18", "init", "init_elements", "init_element",
  "prob_inits", "simple_init", "one_inits", "one_init", "value",
  "goal_spec", "goal_reward", "metric_spec", "$@19", "$@20", "formula",
  "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28",
  "conjuncts", "disjuncts", "atomic_term_formula", "$@29",
  "atomic_name_formula", "$@30", "f_exp", "term_or_f_exp", "$@31", "$@32",
  "$@33", "$@34", "$@35", "opt_f_exp", "f_head", "$@36", "ground_f_exp",
  "opt_ground_f_exp", "ground_f_head", "$@37", "terms", "names",
  "variables", "$@38", "variable_seq", "typed_names", "$@39", "name_seq",
  "type_spec", "$@40", "type", "types", "function_type", "define",
  "domain", "problem", "when", "not", "and", "or", "imply", "exists",
  "forall", "probabilistic", "assign", "scale_up", "scale_down",
  "increase", "decrease", "minimize", "maximize", "number", "object",
  "either", "type_name", "predicate", "function", "name", "variable", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    40,    41,    45,    61,    60,    62,
      43,    42,    47
};
# endif

#define YYPACT_NINF -380

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-380)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -380,    24,  -380,  -380,    21,    91,  -380,  -380,  -380,    38,
     114,  -380,  -380,  1028,  1028,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,    41,    47,  -380,
      66,    74,    82,   133,    88,  -380,  -380,    99,  -380,   101,
     113,   122,   124,   125,  -380,  1028,   992,  -380,  -380,  -380,
    -380,  1028,  -380,   150,  -380,    72,  -380,    67,  -380,    60,
    -380,    99,   128,   134,    25,  -380,    99,   128,   140,    11,
    -380,    99,   134,   140,   143,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  1109,  -380,  1028,  1028,    83,   141,  -380,    77,
    -380,    99,    99,    18,  -380,    99,    99,  -380,    15,  -380,
      99,    99,  -380,  -380,  -380,  -380,  -380,   145,   527,  -380,
     146,   327,  -380,  -380,  1028,   149,     7,  -380,   154,    99,
      99,    99,   151,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,   141,  -380,   152,   119,    28,   153,   158,
    -380,  -380,   161,   166,  -380,  -380,   288,  1028,   163,   163,
     181,  -380,   163,   938,   970,   175,  -380,   212,  -380,  -380,
    -380,   938,   118,   160,  -380,  -380,     3,  -380,    89,  -380,
    -380,   188,  -380,  -380,  -380,  -380,  -380,   182,   -25,  -380,
     183,  -380,  -380,  -380,   191,   495,  -380,  -380,  -380,  1054,
    -380,  -380,  -380,  -380,  -380,  1028,   416,   192,  -380,  -380,
    -380,  -380,  -380,  1059,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,   818,  -380,  -380,
     938,  -380,  -380,   938,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,   982,  -380,  -380,   199,  -380,
    -380,  -380,  -380,  -380,   200,   250,  -380,  -380,  -380,  -380,
     202,   788,   788,   255,  -380,  -380,   163,   850,   850,  -380,
     393,  -380,  -380,  -380,   850,   850,   206,   702,  -380,   938,
     208,   213,  -380,   938,   327,   214,   730,   216,  -380,   -18,
     970,   880,   880,   880,   880,   880,  -380,   912,   199,  -380,
     131,  -380,  -380,  -380,  -380,  -380,   319,   221,  -380,  -380,
     222,  -380,  -380,  -380,  -380,  -380,   463,   850,  -380,  -380,
     850,  -380,  -380,  -380,  -380,  -380,   818,   850,   850,  -380,
    -380,  -380,   743,   225,   163,   163,   554,   970,  -380,  -380,
    -380,   163,  -380,   970,  -380,  1028,   850,   850,   850,   850,
     850,  1028,   234,   996,    34,  -380,   788,   237,   248,   788,
     788,   788,   788,  -380,  -380,  -380,   850,   850,   850,   850,
    -380,   249,   251,   850,   850,   850,   850,  -380,   253,   254,
     256,  -380,  -380,  -380,   260,   261,  -380,  -380,  -380,   262,
     264,  -380,   269,   270,   271,   272,   273,   274,   346,  -380,
    -380,  -380,  -380,   996,   644,   275,  -380,  -380,   788,   788,
     788,   788,  -380,   850,   850,   850,   850,  -380,  -380,  -380,
     850,   850,   850,   850,   585,  -380,  -380,  -380,   938,   938,
    -380,   970,  -380,  -380,  -380,  -380,  -380,  -380,   912,  -380,
    -380,  -380,  -380,   282,  -380,   289,   290,   312,   321,   672,
    -380,   328,   329,   330,   339,   613,   340,   342,   343,   344,
    -380,   345,   347,   349,   285,   760,   227,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,   350,   228,  -380,  -380,
    -380
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     4,     1,     3,     0,     5,     6,   254,     0,
       0,   255,   256,     0,     0,   286,   287,   288,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   289,   290,   291,   307,     0,     0,     7,
       0,     9,     0,     0,     0,    12,    15,    22,    47,    10,
      13,    16,    17,    18,    49,     0,     0,    70,    72,    77,
      75,     0,     8,     0,    48,     0,    11,     0,    14,     0,
      19,    27,    23,    24,     0,    20,    32,    28,    29,     0,
      21,    37,    33,    34,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    51,   238,   238,     0,    81,    90,     0,
      25,    40,    38,     0,    26,    43,    41,    30,     0,    31,
      46,    44,    35,    36,   124,    50,    52,     0,   239,   242,
       0,     0,    74,    78,     0,     0,    82,    84,    92,    39,
      42,    45,   153,    71,   244,   240,   243,    73,   275,   276,
     277,   279,   280,   284,   283,   278,   281,   282,    79,    88,
     285,    76,    86,    81,    85,     0,    96,     0,   153,     0,
     127,   129,   153,   153,   131,   150,     0,   238,   232,   232,
       0,    83,   232,     0,     0,     0,    95,    96,    97,   132,
     135,     0,     0,     0,   126,   125,     0,   128,     0,   130,
     273,     0,   245,   246,   247,   241,   308,     0,   233,   236,
       0,   272,    87,   253,     0,     0,    98,   158,   184,     0,
      99,   100,   112,    91,    94,   238,     0,     0,   270,   271,
     156,   154,   274,     0,    80,   234,   237,    89,    93,   258,
     259,   260,   261,   262,   263,   163,   165,     0,   161,   167,
       0,   178,   171,     0,   174,   176,   182,   257,   264,   265,
     266,   267,   268,   269,   104,     0,   107,   102,     0,   114,
     116,   118,   120,   122,     0,     0,   134,   136,   137,   187,
     153,     0,     0,     0,   249,   250,   232,     0,     0,   194,
       0,   159,   205,   206,     0,     0,     0,     0,   180,     0,
       0,     0,   227,     0,     0,     0,     0,     0,   111,     0,
       0,     0,     0,     0,     0,     0,   133,     0,     0,   185,
       0,   149,   151,   219,   221,   212,     0,     0,   217,   226,
       0,   248,   251,   252,   235,   188,     0,     0,   193,   211,
       0,   197,   195,   199,   201,   203,     0,     0,     0,   169,
     170,   179,     0,     0,   232,   232,     0,     0,   113,   101,
     108,   232,   106,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   230,     0,     0,     0,     0,
       0,     0,     0,   224,   157,   155,     0,     0,     0,     0,
     209,     0,     0,     0,     0,     0,     0,   227,     0,     0,
       0,   172,   181,   173,     0,     0,   183,   228,   229,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,   140,
     142,   146,   139,     0,     0,     0,   218,   220,   222,     0,
       0,     0,   230,   207,     0,     0,     0,   227,   164,   166,
     207,     0,     0,     0,     0,   160,   162,   168,     0,     0,
     105,     0,   115,   117,   119,   121,   123,   138,     0,   144,
     141,   186,   231,   153,   223,     0,     0,     0,     0,     0,
     208,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     204,     0,     0,     0,     0,     0,     0,   152,   214,   213,
     215,   216,   225,   190,   189,   191,   192,   210,   198,   196,
     200,   202,   175,   177,   103,   148,     0,     0,   143,   145,
     147
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -380,  -380,  -380,  -380,  -380,  -380,  -380,   229,   303,  -380,
    -380,  -380,   315,   334,   335,   -23,    98,   280,  -380,   322,
    -380,  -380,   -27,  -380,    50,   -20,  -380,  -380,  -380,  -380,
     263,  -380,  -380,  -380,   281,  -380,  -380,  -380,  -380,  -380,
     236,  -380,  -380,  -289,  -380,  -380,  -380,  -380,  -296,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,   257,   258,
    -380,  -380,  -380,  -380,  -380,  -380,     4,  -380,   -57,  -380,
     259,  -380,  -273,  -380,  -380,  -186,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -181,  -380,   203,  -380,
    -167,   105,  -380,  -380,  -380,  -380,  -380,    12,  -178,  -380,
    -272,  -380,  -303,  -380,  -379,    22,  -170,  -380,  -380,   -94,
    -380,  -380,   247,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,   238,  -211,  -380,  -380,  -380,   239,   185,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -217,  -380,  -161,  -129,
    -130,   -13,  -202
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     6,    41,    44,    45,    46,    70,
      75,    80,   110,   114,   119,    47,    48,    49,   102,   103,
      50,   104,    51,   105,    52,    53,   107,   106,   133,   178,
     135,   136,   163,   180,   137,   179,    54,   138,   166,   185,
     186,   187,   188,   220,   307,   303,   306,   309,   310,   221,
     311,   312,   313,   314,   315,     7,   142,   169,   170,   171,
     172,   225,   173,   226,   277,   374,   419,   485,   420,   506,
     174,   321,   175,   282,   281,   216,   346,   294,   287,   288,
     295,   298,   300,   301,   297,   352,   217,   302,   421,   375,
     470,   291,   394,   393,   395,   396,   397,   471,   338,   437,
     327,   465,   328,   432,   356,   424,   207,   286,   208,   127,
     177,   128,   145,   176,   202,   283,   212,     9,    13,    14,
     264,   250,   251,   252,   253,   254,   255,   268,   269,   270,
     271,   272,   273,   230,   231,   213,   203,   233,   157,   218,
     339,   160,   209
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      37,    38,   158,   222,   159,   227,   236,   322,   266,   210,
     330,   130,   214,   363,   372,   204,   284,   360,   444,    58,
      59,   364,   373,    58,     3,    77,    82,    59,    71,    76,
      81,    73,    78,    58,    56,    60,   206,   190,   191,    61,
     192,   144,    84,    61,   308,   293,    61,   362,   108,   111,
     115,   121,   112,    61,   111,   120,   121,   112,   475,   115,
     120,   189,   190,   191,   296,   192,   332,   299,   409,    59,
      60,   134,   285,   162,   411,    58,    59,    60,   423,    57,
      58,    59,    60,   205,   305,     5,   256,    60,    61,   139,
     256,   129,   129,   140,     8,    61,   308,   279,   141,   422,
      61,    72,    10,    83,   425,    61,    39,   428,   429,   430,
     431,   351,    40,   353,    55,   146,   334,   357,    11,    12,
     337,   340,   333,   116,   191,   222,   192,   347,   348,   222,
      42,   274,   116,   366,   367,   368,   369,   370,    43,    56,
      57,    58,    59,    60,   293,    64,   319,   131,   132,   183,
     184,   329,   329,    62,   408,   484,   464,   466,   467,   468,
     345,    61,   483,    63,   129,    65,   402,   376,   192,    64,
     391,   228,   229,   392,    64,   256,   222,    67,    61,    64,
     399,   400,   222,   165,   404,   405,    69,   329,    74,    79,
     487,   410,   109,   189,   190,   191,   383,   192,   113,   412,
     413,   414,   415,   416,   118,   134,   390,   459,   124,    64,
     143,   147,   129,    64,   161,   167,   182,   193,    64,   433,
     434,   435,   436,   195,   206,   196,   440,   441,   442,   443,
     198,   148,   149,   150,   292,   390,   211,    64,    64,    64,
     223,   383,   408,   184,   279,   232,   329,   234,   237,   329,
     329,   329,   329,   148,   149,   150,   238,   280,   148,   149,
     150,   308,   481,   482,   192,   316,   320,   472,   473,   474,
     222,   349,   354,   408,   477,   478,   479,   355,    66,   358,
     361,   151,   152,   153,   154,   155,   384,   385,   156,   319,
     403,   148,   149,   150,   279,   458,   417,   258,   329,   329,
     329,   329,   426,   151,   152,   153,   154,   155,   151,   152,
     156,   200,   155,   427,   438,   156,   439,   317,   445,   446,
     331,   447,    15,    16,    17,   448,   449,   450,   329,   451,
     148,   149,   150,   292,   452,   453,   454,   455,   456,   457,
     463,   151,   152,   407,   200,   155,   486,   505,   156,   148,
     149,   150,   201,    68,   488,   489,   279,   377,   378,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   490,   319,    36,
     151,   152,   153,   154,   155,   379,   491,   156,   240,   380,
     381,   382,   117,   493,   494,   495,    15,    16,    17,   151,
     152,   153,   154,   155,   496,   498,   156,   499,   500,   501,
     502,   462,   503,   458,   504,   510,   122,   164,   123,   148,
     149,   150,   168,   224,   126,   194,   181,   460,   509,   278,
     197,   407,   199,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,   398,   476,    36,   469,   235,   462,   265,   267,   341,
     318,     0,   407,   342,   343,   344,    15,    16,    17,   151,
     152,   153,   154,   155,     0,     0,   156,     0,     0,     0,
     275,   276,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   149,
     150,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,    36,     0,     0,     0,     0,     0,   386,
      15,    16,    17,   387,   388,   389,   239,   240,   241,   242,
     243,   244,     0,     0,     0,     0,     0,     0,   151,   152,
     153,   154,   155,   245,   246,   156,     0,    15,    16,    17,
       0,     0,   247,   248,   249,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,    36,    15,    16,
      17,     0,     0,   144,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,    36,   206,    15,    16,    17,   406,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,    36,   206,    15,    16,    17,
     480,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,    36,   206,    15,    16,    17,   497,     0,
       0,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,    36,   148,   149,   150,     0,   461,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,    36,   148,   149,   150,     0,   492,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,   150,     0,
       0,     0,     0,     0,     0,   151,   152,   153,   154,   155,
       0,     0,   156,   148,   149,   150,   215,   350,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   151,   152,   153,   154,   155,     0,     0,
     156,    15,    16,    17,   219,   359,   151,   152,   153,   154,
     155,     0,     0,   156,     0,     0,     0,   215,   401,     0,
       0,     0,     0,   151,   152,   153,   154,   155,     0,     0,
     156,    15,    16,    17,   507,   508,   323,   324,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,    36,     0,
     325,     0,   326,    15,    16,    17,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,    36,   206,
     289,     0,   290,    15,    16,    17,     0,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
      36,     0,   335,     0,   336,    15,    16,    17,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
      36,   148,   149,   150,   365,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,    36,   148,   149,   150,   371,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   149,   150,     0,     0,
       0,   151,   152,   153,   154,   155,     0,     0,   156,   148,
     149,   150,   215,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
       0,     0,     0,   151,   152,   153,   154,   155,     0,     0,
     156,    15,    16,    17,   219,   151,   152,   153,   154,   155,
       0,     0,   156,     0,     0,     0,   304,     0,     0,   151,
     152,   153,   154,   155,     0,     0,   156,   148,   149,   150,
     418,     0,   148,   149,   150,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,    36,     0,
       0,     0,     0,     0,   257,   239,   240,     0,     0,     0,
     244,   258,   259,   260,   261,   262,   263,   151,   152,   153,
     154,   155,   151,   152,   156,   200,   155,     0,     0,   156,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125
};

static const yytype_int16 yycheck[] =
{
      13,    14,   131,   184,   134,   191,   208,   280,   219,   179,
     282,   105,   182,   309,   317,   176,   233,   306,   397,     8,
       9,   310,   318,     8,     0,    52,    53,     9,    51,    52,
      53,    51,    52,     8,     6,    10,    61,    34,    35,    28,
      37,    66,    55,    28,    62,   247,    28,    65,    61,    72,
      73,    78,    72,    28,    77,    78,    83,    77,   437,    82,
      83,    33,    34,    35,   250,    37,   283,   253,   357,     9,
      10,    64,   233,    66,   363,     8,     9,    10,   374,     7,
       8,     9,    10,   177,   265,    64,   215,    10,    28,   112,
     219,   104,   105,   116,     3,    28,    62,   226,   121,    65,
      28,    51,    64,    53,   376,    28,    65,   379,   380,   381,
     382,   297,    65,   299,    32,   128,   286,   303,     4,     5,
     287,   288,   283,    73,    35,   306,    37,   294,   295,   310,
      64,   225,    82,   311,   312,   313,   314,   315,    64,     6,
       7,     8,     9,    10,   346,    47,   275,    64,    65,    30,
      31,   281,   282,    65,   356,   458,   428,   429,   430,   431,
     290,    28,   451,    64,   177,    64,   352,    36,    37,    71,
     337,    53,    54,   340,    76,   304,   357,    64,    28,    81,
     347,   348,   363,    29,   354,   355,    64,   317,    64,    64,
     463,   361,    64,    33,    34,    35,   326,    37,    64,   366,
     367,   368,   369,   370,    64,    64,   336,   418,    65,   111,
      65,    65,   225,   115,    65,    64,    64,    64,   120,   386,
     387,   388,   389,    65,    61,    64,   393,   394,   395,   396,
      64,     3,     4,     5,   247,   365,    55,   139,   140,   141,
      65,   371,   444,    31,   373,    57,   376,    65,    65,   379,
     380,   381,   382,     3,     4,     5,    65,    65,     3,     4,
       5,    62,   448,   449,    37,    65,    64,   434,   435,   436,
     451,    65,    64,   475,   441,   442,   443,    64,    49,    65,
      64,    53,    54,    55,    56,    57,    65,    65,    60,   418,
      65,     3,     4,     5,   423,    67,    62,    47,   428,   429,
     430,   431,    65,    53,    54,    55,    56,    57,    53,    54,
      60,    56,    57,    65,    65,    60,    65,    67,    65,    65,
      65,    65,     3,     4,     5,    65,    65,    65,   458,    65,
       3,     4,     5,   346,    65,    65,    65,    65,    65,    65,
      65,    53,    54,   356,    56,    57,    64,    62,    60,     3,
       4,     5,    64,    50,    65,    65,   485,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    65,   507,    60,
      53,    54,    55,    56,    57,    66,    65,    60,    42,    70,
      71,    72,    77,    65,    65,    65,     3,     4,     5,    53,
      54,    55,    56,    57,    65,    65,    60,    65,    65,    65,
      65,   424,    65,    67,    65,    65,    82,   136,    83,     3,
       4,     5,   142,   187,   102,   168,   163,   423,   485,   226,
     172,   444,   173,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   346,   440,    60,   432,   208,   469,   219,   219,    66,
     275,    -1,   475,    70,    71,    72,     3,     4,     5,    53,
      54,    55,    56,    57,    -1,    -1,    60,    -1,    -1,    -1,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,
       3,     4,     5,    70,    71,    72,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,     3,     4,     5,
      -1,    -1,    67,    68,    69,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    60,     3,     4,
       5,    -1,    -1,    66,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,     3,     4,     5,    65,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    60,    61,     3,     4,     5,
      65,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    60,    61,     3,     4,     5,    65,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,     3,     4,     5,    -1,    65,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,     3,     4,     5,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      -1,    -1,    60,     3,     4,     5,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,    -1,
      60,     3,     4,     5,    64,    65,    53,    54,    55,    56,
      57,    -1,    -1,    60,    -1,    -1,    -1,    64,    65,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,    -1,
      60,     3,     4,     5,    64,    65,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    60,    -1,
      62,    -1,    64,     3,     4,     5,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    60,    61,
      62,    -1,    64,     3,     4,     5,    -1,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      60,    -1,    62,    -1,    64,     3,     4,     5,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      60,     3,     4,     5,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,     3,     4,     5,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    -1,    -1,    60,     3,
       4,     5,    64,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,    -1,
      60,     3,     4,     5,    64,    53,    54,    55,    56,    57,
      -1,    -1,    60,    -1,    -1,    -1,    64,    -1,    -1,    53,
      54,    55,    56,    57,    -1,    -1,    60,     3,     4,     5,
      64,    -1,     3,     4,     5,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    53,    54,    60,    56,    57,    -1,    -1,    60,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    74,    75,     0,    76,    64,    77,   128,     3,   190,
      64,     4,     5,   191,   192,     3,     4,     5,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    60,   214,   214,    65,
      65,    78,    64,    64,    79,    80,    81,    88,    89,    90,
      93,    95,    97,    98,   109,    32,     6,     7,     8,     9,
      10,    28,    65,    64,    89,    64,    80,    64,    81,    64,
      82,    88,    97,    98,    64,    83,    88,    95,    98,    64,
      84,    88,    95,    97,   214,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    91,    92,    94,    96,   100,    99,   214,    64,
      85,    88,    98,    64,    86,    88,    97,    85,    64,    87,
      88,    95,    86,    87,    65,    65,    92,   182,   184,   214,
     182,    64,    65,   101,    64,   103,   104,   107,   110,    88,
      88,    88,   129,    65,    66,   185,   214,    65,     3,     4,
       5,    53,    54,    55,    56,    57,    60,   211,   212,   213,
     214,    65,    66,   105,   107,    29,   111,    64,    90,   130,
     131,   132,   133,   135,   143,   145,   186,   183,   102,   108,
     106,   103,    64,    30,    31,   112,   113,   114,   115,    33,
      34,    35,    37,    64,   131,    65,    64,   132,    64,   143,
      56,    64,   187,   209,   211,   182,    61,   179,   181,   215,
     179,    55,   189,   208,   179,    64,   148,   159,   212,    64,
     116,   122,   159,    65,   113,   134,   136,   148,    53,    54,
     206,   207,    57,   210,    65,   185,   215,    65,    65,    41,
      42,    43,    44,    45,    46,    58,    59,    67,    68,    69,
     194,   195,   196,   197,   198,   199,   212,    40,    47,    48,
      49,    50,    51,    52,   193,   194,   195,   199,   200,   201,
     202,   203,   204,   205,   182,    64,    65,   137,   161,   212,
      65,   147,   146,   188,   209,   211,   180,   151,   152,    62,
      64,   164,   214,   215,   150,   153,   148,   157,   154,   148,
     155,   156,   160,   118,    64,   159,   119,   117,    62,   120,
     121,   123,   124,   125,   126,   127,    65,    67,   200,   212,
      64,   144,   145,    38,    39,    62,    64,   173,   175,   213,
     173,    65,   209,   211,   179,    62,    64,   163,   171,   213,
     163,    66,    70,    71,    72,   213,   149,   163,   163,    65,
      65,   148,   158,   148,    64,    64,   177,   148,    65,    65,
     116,    64,    65,   121,   116,    64,   171,   171,   171,   171,
     171,    64,   175,   121,   138,   162,    36,    38,    39,    66,
      70,    71,    72,   213,    65,    65,    66,    70,    71,    72,
     213,   163,   163,   166,   165,   167,   168,   169,   164,   163,
     163,    65,   148,    65,   179,   179,    65,   214,   215,   116,
     179,   116,   163,   163,   163,   163,   163,    62,    64,   139,
     141,   161,    65,   121,   178,   173,    65,    65,   173,   173,
     173,   173,   176,   163,   163,   163,   163,   172,    65,    65,
     163,   163,   163,   163,   177,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    67,   195,
     139,    65,   214,    65,   173,   174,   173,   173,   173,   178,
     163,   170,   163,   163,   163,   177,   170,   163,   163,   163,
      65,   148,   148,   116,   175,   140,    64,   145,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    62,   142,    64,    65,   141,
      65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    75,    74,    76,    76,    76,    78,    77,    79,
      79,    79,    79,    80,    80,    80,    81,    81,    81,    81,
      81,    81,    81,    82,    82,    82,    82,    82,    83,    83,
      83,    83,    83,    84,    84,    84,    84,    84,    85,    85,
      85,    86,    86,    86,    87,    87,    87,    88,    88,    89,
      90,    91,    91,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      94,    93,    96,    95,    97,    99,    98,   100,   100,   102,
     101,   103,   103,   103,   104,   104,   106,   105,   108,   107,
     110,   109,   111,   111,   112,   112,   113,   113,   114,   115,
     116,   116,   117,   116,   118,   116,   116,   119,   119,   120,
     120,   121,   122,   122,   123,   122,   124,   122,   125,   122,
     126,   122,   127,   122,   129,   128,   130,   130,   131,   131,
     132,   132,   134,   133,   135,   136,   136,   137,   137,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   142,   143,
     143,   144,   144,   145,   146,   145,   147,   145,   148,   149,
     148,   150,   148,   151,   148,   152,   148,   153,   148,   148,
     148,   154,   148,   148,   155,   148,   156,   148,   157,   157,
     158,   158,   160,   159,   159,   162,   161,   161,   163,   163,
     163,   163,   163,   163,   164,   165,   164,   166,   164,   167,
     164,   168,   164,   169,   164,   164,   164,   170,   170,   172,
     171,   171,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   174,   174,   176,   175,   175,   177,   177,   177,
     178,   178,   179,   179,   180,   179,   181,   181,   182,   182,
     183,   182,   184,   184,   186,   185,   187,   187,   187,   188,
     188,   188,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   211,   211,   211,   211,
     211,   211,   212,   212,   212,   213,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   215
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     2,     0,     9,     0,
       1,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       2,     2,     1,     1,     1,     2,     2,     1,     1,     1,
       2,     2,     1,     1,     1,     2,     2,     1,     1,     2,
       1,     1,     2,     1,     1,     2,     1,     1,     2,     1,
       4,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     0,     5,     4,     0,     5,     0,     2,     0,
       5,     0,     1,     3,     1,     2,     0,     3,     0,     5,
       0,     7,     0,     4,     2,     1,     0,     1,     2,     2,
       1,     4,     0,     8,     0,     6,     4,     0,     2,     2,
       3,     1,     1,     4,     0,     6,     0,     6,     0,     6,
       0,     6,     0,     6,     0,    13,     2,     1,     2,     1,
       2,     1,     0,     5,     4,     0,     2,     1,     5,     4,
       2,     3,     1,     4,     0,     2,     1,     5,     1,     5,
       1,     1,     5,     0,     0,     6,     0,     6,     1,     0,
       6,     0,     6,     0,     6,     0,     6,     0,     6,     4,
       4,     0,     5,     5,     0,     8,     0,     8,     0,     2,
       0,     2,     0,     5,     1,     0,     5,     1,     1,     5,
       5,     5,     5,     1,     1,     0,     6,     0,     6,     0,
       6,     0,     6,     0,     5,     1,     1,     0,     1,     0,
       5,     1,     1,     5,     5,     5,     5,     1,     3,     1,
       3,     1,     0,     1,     0,     5,     1,     0,     2,     2,
       0,     2,     0,     1,     0,     4,     1,     2,     0,     1,
       0,     4,     1,     2,     0,     3,     1,     1,     4,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if PPDDL_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !PPDDL_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !PPDDL_DEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 305 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { success = true; line_number = 1; }
#line 2072 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 306 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { if (!success) YYERROR; }
#line 2078 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 318 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { make_domain((yyvsp[-1].str)); }
#line 2084 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 392 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { requirements->strips = true; }
#line 2090 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 393 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { requirements->typing = true; }
#line 2096 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 395 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { requirements->negative_preconditions = true; }
#line 2102 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 397 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { requirements->disjunctive_preconditions = true; }
#line 2108 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 398 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { requirements->equality = true; }
#line 2114 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 400 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { requirements->existential_preconditions = true; }
#line 2120 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 402 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { requirements->universal_preconditions = true; }
#line 2126 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 404 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { requirements->quantified_preconditions(); }
#line 2132 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 405 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { requirements->conditional_effects = true; }
#line 2138 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 406 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { requirements->fluents = true; }
#line 2144 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 407 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { requirements->adl(); }
#line 2150 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 409 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    {
                  throw std::runtime_error("`:durative-actions'"
                                           " not supported");
                }
#line 2159 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 414 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    {
                  throw std::runtime_error("`:duration-inequalities'"
                                           " not supported");
                }
#line 2168 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 419 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    {
                  throw std::runtime_error("`:continuous-effects'"
                                           " not supported");
                }
#line 2177 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 424 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    {
                  requirements->probabilistic_effects = true;
                }
#line 2185 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 428 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    {
                  requirements->rewards = true;
                  reward_function = domain->functions().add_function("reward");
                }
#line 2194 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 433 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    {
                  requirements->mdp();
                  reward_function = domain->functions().add_function("reward");
                }
#line 2203 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 439 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_typing(); name_kind = TYPE_KIND; }
#line 2209 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 440 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2215 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 443 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { name_kind = CONSTANT_KIND; }
#line 2221 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 444 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2227 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 450 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2233 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 461 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { make_predicate((yyvsp[0].str)); }
#line 2239 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 462 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { predicate = 0; }
#line 2245 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 474 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_typing(); }
#line 2251 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 477 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { make_function((yyvsp[0].str)); }
#line 2257 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 478 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { function = 0; }
#line 2263 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 485 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { make_action((yyvsp[0].str)); }
#line 2269 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 486 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { add_action(); }
#line 2275 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 98:
#line 501 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { action->set_precondition(*(yyvsp[0].formula)); }
#line 2281 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 99:
#line 504 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { action->set_effect(*(yyvsp[0].effect)); }
#line 2287 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 101:
#line 512 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = (yyvsp[-1].effect); }
#line 2293 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 513 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { prepare_forall_effect(); }
#line 2299 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 514 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = make_forall_effect(*(yyvsp[-1].effect)); }
#line 2305 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 104:
#line 515 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_conditional_effects(); }
#line 2311 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 105:
#line 516 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = &ConditionalEffect::make(*(yyvsp[-2].formula), *(yyvsp[-1].effect)); }
#line 2317 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 518 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = make_prob_effect((yyvsp[-1].outcomes)); }
#line 2323 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 521 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = &Effect::EMPTY; }
#line 2329 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 108:
#line 522 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = &(*(yyvsp[-1].effect) && *(yyvsp[0].effect)); }
#line 2335 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 109:
#line 526 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    {
                (yyval.outcomes) = new std::vector<std::pair<Rational, const Effect*> >();
                add_outcome(*(yyval.outcomes), (yyvsp[-1].num), *(yyvsp[0].effect));
              }
#line 2344 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 110:
#line 531 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.outcomes) = (yyvsp[-2].outcomes); add_outcome(*(yyval.outcomes), (yyvsp[-1].num), *(yyvsp[0].effect)); }
#line 2350 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 112:
#line 537 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = make_add_effect(*(yyvsp[0].atom)); }
#line 2356 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 538 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = make_delete_effect(*(yyvsp[-1].atom)); }
#line 2362 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 114:
#line 539 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { effect_fluent = true; }
#line 2368 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 115:
#line 540 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = make_assign_effect(*(yyvsp[-2].fluent), *(yyvsp[-1].expr)); }
#line 2374 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 116:
#line 541 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { effect_fluent = true; }
#line 2380 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 117:
#line 542 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = make_scale_up_effect(*(yyvsp[-2].fluent), *(yyvsp[-1].expr)); }
#line 2386 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 118:
#line 543 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { effect_fluent = true; }
#line 2392 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 119:
#line 544 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = make_scale_down_effect(*(yyvsp[-2].fluent), *(yyvsp[-1].expr)); }
#line 2398 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 120:
#line 545 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { effect_fluent = true; }
#line 2404 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 121:
#line 546 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = make_increase_effect(*(yyvsp[-2].fluent), *(yyvsp[-1].expr)); }
#line 2410 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 547 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { effect_fluent = true; }
#line 2416 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 548 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = make_decrease_effect(*(yyvsp[-2].fluent), *(yyvsp[-1].expr)); }
#line 2422 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 124:
#line 556 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { make_problem((yyvsp[-5].str), (yyvsp[-1].str)); }
#line 2428 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 125:
#line 557 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { problem->instantiate(); delete requirements; }
#line 2434 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 572 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { name_kind = OBJECT_KIND; }
#line 2440 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 573 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { name_kind = VOID_KIND; }
#line 2446 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 137:
#line 583 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { problem->add_init_atom(*(yyvsp[0].atom)); }
#line 2452 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 138:
#line 585 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { problem->add_init_value(*(yyvsp[-2].fluent), *(yyvsp[-1].num)); delete (yyvsp[-1].num); }
#line 2458 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 587 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { problem->add_init_effect(*make_prob_effect((yyvsp[-1].outcomes))); }
#line 2464 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 591 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    {
                 (yyval.outcomes) = new std::vector<std::pair<Rational, const Effect*> >();
                 add_outcome(*(yyval.outcomes), (yyvsp[-1].num), *(yyvsp[0].effect));
               }
#line 2473 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 596 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.outcomes) = (yyvsp[-2].outcomes); add_outcome(*(yyval.outcomes), (yyvsp[-1].num), *(yyvsp[0].effect)); }
#line 2479 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 600 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = (yyvsp[-1].effect); }
#line 2485 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 144:
#line 603 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = &Effect::EMPTY; }
#line 2491 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 604 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = &(*(yyvsp[-1].effect) && *(yyvsp[0].effect)); }
#line 2497 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 146:
#line 607 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = make_add_effect(*(yyvsp[0].atom)); }
#line 2503 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 147:
#line 609 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.effect) = make_assign_effect(*(yyvsp[-2].fluent), *(yyvsp[-1].expr)); }
#line 2509 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 148:
#line 612 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value(*(yyvsp[0].num)); delete (yyvsp[0].num); }
#line 2515 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 149:
#line 615 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { problem->set_goal(*(yyvsp[-2].formula)); }
#line 2521 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 152:
#line 621 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { set_goal_reward(*(yyvsp[-2].expr)); }
#line 2527 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 153:
#line 624 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { set_default_metric(); }
#line 2533 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 154:
#line 625 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { metric_fluent = true; }
#line 2539 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 155:
#line 626 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { problem->set_metric(*(yyvsp[-1].expr)); metric_fluent = false; }
#line 2545 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 156:
#line 627 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { metric_fluent = true; }
#line 2551 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 157:
#line 628 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { problem->set_metric(*(yyvsp[-1].expr), true); metric_fluent = false; }
#line 2557 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 158:
#line 634 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[0].atom); }
#line 2563 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 159:
#line 636 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { first_eq_term = eq_term; first_eq_expr = eq_expr; }
#line 2569 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 160:
#line 637 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_equality(); }
#line 2575 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 161:
#line 638 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2581 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 162:
#line 639 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = &LessThan::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2587 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 163:
#line 640 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2593 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 164:
#line 641 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = &LessThanOrEqualTo::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2599 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 165:
#line 642 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2605 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 166:
#line 643 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = &GreaterThanOrEqualTo::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2611 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 167:
#line 644 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2617 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 168:
#line 645 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = &GreaterThan::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2623 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 169:
#line 646 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_negation(*(yyvsp[-1].formula)); }
#line 2629 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 170:
#line 647 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2635 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 171:
#line 648 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_disjunction(); }
#line 2641 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 172:
#line 648 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = (yyvsp[-1].formula); }
#line 2647 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 173:
#line 649 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_implication(*(yyvsp[-2].formula), *(yyvsp[-1].formula)); }
#line 2653 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 174:
#line 650 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { prepare_exists(); }
#line 2659 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 175:
#line 651 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_exists(*(yyvsp[-1].formula)); }
#line 2665 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 176:
#line 652 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { prepare_forall(); }
#line 2671 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 177:
#line 653 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = make_forall(*(yyvsp[-1].formula)); }
#line 2677 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 178:
#line 656 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = &StateFormula::TRUE; }
#line 2683 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 179:
#line 657 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) && *(yyvsp[0].formula)); }
#line 2689 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 180:
#line 660 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = &StateFormula::FALSE; }
#line 2695 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 181:
#line 661 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.formula) = &(*(yyvsp[-1].formula) || *(yyvsp[0].formula)); }
#line 2701 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 182:
#line 664 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2707 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 183:
#line 665 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.atom) = make_atom(); }
#line 2713 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 184:
#line 666 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); (yyval.atom) = make_atom(); }
#line 2719 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 185:
#line 669 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); }
#line 2725 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 186:
#line 670 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.atom) = make_atom(); }
#line 2731 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 187:
#line 671 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { prepare_atom((yyvsp[0].str)); (yyval.atom) = make_atom(); }
#line 2737 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 188:
#line 678 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value(*(yyvsp[0].num)); delete (yyvsp[0].num); }
#line 2743 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 189:
#line 679 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2749 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 190:
#line 680 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 2755 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 191:
#line 681 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2761 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 192:
#line 682 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2767 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 193:
#line 683 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].fluent); }
#line 2773 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 194:
#line 687 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_fluents(); eq_expr = new Value(*(yyvsp[0].num)); delete (yyvsp[0].num); }
#line 2779 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 195:
#line 688 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2785 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 196:
#line 689 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { eq_expr = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2791 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 197:
#line 690 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2797 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 198:
#line 691 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { eq_expr = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 2803 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 199:
#line 692 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2809 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 200:
#line 693 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { eq_expr = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2815 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 201:
#line 694 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_fluents(); }
#line 2821 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 202:
#line 695 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { eq_expr = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2827 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 203:
#line 696 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_fluents(); prepare_fluent((yyvsp[0].str)); }
#line 2833 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 204:
#line 697 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { eq_expr = make_fluent(); }
#line 2839 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 205:
#line 698 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { make_eq_name((yyvsp[0].str)); }
#line 2845 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 206:
#line 699 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { eq_term = make_term((yyvsp[0].str)); eq_expr = 0; }
#line 2851 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 207:
#line 702 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 2857 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 209:
#line 706 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); }
#line 2863 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 210:
#line 706 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.fluent) = make_fluent(); }
#line 2869 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 211:
#line 707 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); (yyval.fluent) = make_fluent(); }
#line 2875 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 212:
#line 710 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = new Value(*(yyvsp[0].num)); delete (yyvsp[0].num); }
#line 2881 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 213:
#line 712 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Addition::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2887 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 214:
#line 714 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = make_subtraction(*(yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 2893 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 215:
#line 716 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Multiplication::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2899 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 216:
#line 718 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Division::make(*(yyvsp[-2].expr), *(yyvsp[-1].expr)); }
#line 2905 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 217:
#line 719 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].fluent); }
#line 2911 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 218:
#line 721 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Fluent::make(domain->total_time(), TermList()); }
#line 2917 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 219:
#line 723 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Fluent::make(domain->total_time(), TermList()); }
#line 2923 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 220:
#line 725 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Fluent::make(domain->goal_achieved(), TermList()); }
#line 2929 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 221:
#line 727 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = &Fluent::make(domain->goal_achieved(), TermList()); }
#line 2935 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 222:
#line 730 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 2941 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 224:
#line 734 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); }
#line 2947 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 225:
#line 735 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.fluent) = make_fluent(); }
#line 2953 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 226:
#line 736 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { prepare_fluent((yyvsp[0].str)); (yyval.fluent) = make_fluent(); }
#line 2959 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 228:
#line 744 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 2965 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 229:
#line 745 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 2971 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 231:
#line 749 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { add_term((yyvsp[0].str)); }
#line 2977 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 233:
#line 753 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { add_variables((yyvsp[0].strs), TypeTable::OBJECT); }
#line 2983 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 234:
#line 754 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { add_variables((yyvsp[-1].strs), *(yyvsp[0].type)); delete (yyvsp[0].type); }
#line 2989 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 236:
#line 758 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<const std::string*>(1, (yyvsp[0].str)); }
#line 2995 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 237:
#line 759 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[-1].strs); (yyval.strs)->push_back((yyvsp[0].str)); }
#line 3001 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 239:
#line 763 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { add_names((yyvsp[0].strs), TypeTable::OBJECT); }
#line 3007 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 240:
#line 764 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { add_names((yyvsp[-1].strs), *(yyvsp[0].type)); delete (yyvsp[0].type); }
#line 3013 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 242:
#line 767 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.strs) = new std::vector<const std::string*>(1, (yyvsp[0].str)); }
#line 3019 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 243:
#line 768 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.strs) = (yyvsp[-1].strs); (yyval.strs)->push_back((yyvsp[0].str)); }
#line 3025 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 244:
#line 771 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { require_typing(); }
#line 3031 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 245:
#line 771 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 3037 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 246:
#line 774 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(TypeTable::OBJECT); }
#line 3043 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 247:
#line 775 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(make_type((yyvsp[0].str))); }
#line 3049 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 248:
#line 776 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.type) = new Type(make_type(*(yyvsp[-1].types))); delete (yyvsp[-1].types); }
#line 3055 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 249:
#line 779 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.types) = new TypeSet(); }
#line 3061 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 250:
#line 780 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.types) = new TypeSet(); (yyval.types)->insert(make_type((yyvsp[0].str))); }
#line 3067 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 251:
#line 781 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); }
#line 3073 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 252:
#line 782 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); (yyval.types)->insert(make_type((yyvsp[0].str))); }
#line 3079 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 254:
#line 792 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3085 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 255:
#line 795 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3091 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 256:
#line 798 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3097 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 257:
#line 801 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3103 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 258:
#line 804 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3109 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 259:
#line 807 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3115 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 260:
#line 810 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3121 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 261:
#line 813 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3127 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 262:
#line 816 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3133 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 263:
#line 819 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3139 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 264:
#line 822 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3145 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 265:
#line 825 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3151 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 266:
#line 828 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3157 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 267:
#line 831 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3163 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 268:
#line 834 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3169 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 269:
#line 837 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3175 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 270:
#line 840 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3181 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 271:
#line 843 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3187 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 272:
#line 846 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3193 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 273:
#line 849 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3199 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;

  case 274:
#line 852 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1646  */
    { delete (yyvsp[0].str); }
#line 3205 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
    break;


#line 3209 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.cc" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 879 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1906  */


/* Outputs an error message. */
static void yyerror(const std::string& s) {
  std::cerr << PACKAGE ":" << current_file << ':' << line_number << ": " << s
            << std::endl;
  success = false;
}


/* Outputs a warning. */
static void yywarning(const std::string& s) {
  if (warning_level > 0) {
    std::cerr << PACKAGE ":" << current_file << ':' << line_number << ": " << s
              << std::endl;
    if (warning_level > 1) {
      success = false;
    }
  }
}


/* Creates an empty domain with the given name. */
static void make_domain(const std::string* name) {
  domain = new Domain(*name);
  domains[*name] = domain;
  requirements = &domain->requirements;
  problem = 0;
  delete name;
}


/* Creates an empty problem with the given name. */
static void make_problem(const std::string* name,
                         const std::string* domain_name) {
  std::map<std::string, Domain*>::const_iterator di =
    domains.find(*domain_name);
  if (di != domains.end()) {
    domain = (*di).second;
  } else {
    domain = new Domain(*domain_name);
    domains[*domain_name] = domain;
    yyerror("undeclared domain `" + *domain_name + "' used");
  }
  requirements = new Requirements(domain->requirements);
  problem = new Problem(*name, *domain);
  const Fluent& total_time_fluent =
    Fluent::make(domain->total_time(), TermList());
  const Update* total_time_update =
    new Assign(total_time_fluent, *new Value(0));
  problem->add_init_effect(UpdateEffect::make(*total_time_update));
  const Fluent& goal_achieved_fluent =
    Fluent::make(domain->goal_achieved(), TermList());
  const Update* goal_achieved_update =
    new Assign(goal_achieved_fluent, *new Value(0));
  problem->add_init_effect(UpdateEffect::make(*goal_achieved_update));
  if (requirements->rewards) {
    reward_function = *domain->functions().find_function("reward");
    const Fluent& reward_fluent = Fluent::make(reward_function, TermList());
    const Update* reward_update = new Assign(reward_fluent, *new Value(0));
    problem->add_init_effect(UpdateEffect::make(*reward_update));
  }
  delete name;
  delete domain_name;
}


/* Adds :typing to the requirements. */
static void require_typing() {
  if (!requirements->typing) {
    yywarning("assuming `:typing' requirement");
    requirements->typing = true;
  }
}


/* Adds :fluents to the requirements. */
static void require_fluents() {
  if (!requirements->fluents) {
    yywarning("assuming `:fluents' requirement");
    requirements->fluents = true;
  }
}


/* Adds :disjunctive-preconditions to the requirements. */
static void require_disjunction() {
  if (!requirements->disjunctive_preconditions) {
    yywarning("assuming `:disjunctive-preconditions' requirement");
    requirements->disjunctive_preconditions = true;
  }
}


/* Adds :conditional-effects to the requirements. */
static void require_conditional_effects() {
  if (!requirements->conditional_effects) {
    yywarning("assuming `:conditional-effects' requirement");
    requirements->conditional_effects = true;
  }
}


/* Returns a simple type with the given name. */
static const Type& make_type(const std::string* name) {
  const Type* t = domain->types().find_type(*name);
  if (t == 0) {
    t = &domain->types().add_type(*name);
    if (name_kind != TYPE_KIND) {
      yywarning("implicit declaration of type `" + *name + "'");
    }
  }
  delete name;
  return *t;
}


/* Returns the union of the given types. */
static Type make_type(const TypeSet& types) {
  return TypeTable::union_type(types);
}


/* Returns a simple term with the given name. */
static Term make_term(const std::string* name) {
  if ((*name)[0] == '?') {
    const Variable* vp = context.find(*name);
    if (vp != 0) {
      delete name;
      return *vp;
    } else {
      Variable v = TermTable::add_variable(TypeTable::OBJECT);
      context.insert(*name, v);
      yyerror("free variable `" + *name + "' used");
      delete name;
      return v;
    }
  } else {
    TermTable& terms = (problem != 0) ? problem->terms() : domain->terms();
    const Object* o = terms.find_object(*name);
    if (o == 0) {
      size_t n = term_parameters.size();
      if (atom_predicate != 0
          && PredicateTable::parameters(*atom_predicate).size() > n) {
        const Type& t = PredicateTable::parameters(*atom_predicate)[n];
        o = &terms.add_object(*name, t);
      } else {
        o = &terms.add_object(*name, TypeTable::OBJECT);
      }
      yywarning("implicit declaration of object `" + *name + "'");
    }
    delete name;
    return *o;
  }
}


/* Creates a predicate with the given name. */
static void make_predicate(const std::string* name) {
  predicate = domain->predicates().find_predicate(*name);
  if (predicate == 0) {
    repeated_predicate = false;
    predicate = &domain->predicates().add_predicate(*name);
  } else {
    repeated_predicate = true;
    yywarning("ignoring repeated declaration of predicate `" + *name + "'");
  }
  delete name;
}


/* Creates a function with the given name. */
static void make_function(const std::string* name) {
  repeated_function = false;
  function = domain->functions().find_function(*name);
  if (function == 0) {
    function = &domain->functions().add_function(*name);
  } else {
    repeated_function = true;
    if (requirements->rewards && *name == "reward") {
      yywarning("ignoring declaration of reserved function `reward'");
    } else if (*name == "total-time" || *name == "goal-achieved") {
      yywarning("ignoring declaration of reserved function `" + *name + "'");
    } else {
      yywarning("ignoring repeated declaration of function `" + *name + "'");
    }
  }
  delete name;
}


/* Creates an action with the given name. */
static void make_action(const std::string* name) {
  context.push_frame();
  action = new ActionSchema(*name);
  delete name;
}


/* Adds the current action to the current domain. */
static void add_action() {
  context.pop_frame();
  if (domain->find_action(action->name()) == 0) {
    domain->add_action(*action);
  } else {
    yywarning("ignoring repeated declaration of action `"
              + action->name() + "'");
    delete action;
  }
  action = 0;
}


/* Prepares for the parsing of a universally quantified effect. */
static void prepare_forall_effect() {
  if (!requirements->conditional_effects) {
    yywarning("assuming `:conditional-effects' requirement");
    requirements->conditional_effects = true;
  }
  context.push_frame();
  quantified.push_back(Term(0));
}


/* Creates a universally quantified effect. */
static const Effect* make_forall_effect(const Effect& effect) {
  context.pop_frame();
  size_t n = quantified.size() - 1;
  size_t m = n;
  while (quantified[n].variable()) {
    n--;
  }
  VariableList parameters;
  for (size_t i = n + 1; i <= m; i++) {
    parameters.push_back(quantified[i].as_variable());
  }
  quantified.resize(n, Term(0));
  return &QuantifiedEffect::make(parameters, effect);
}


/* Adds an outcome to the given probabilistic effect. */
static void add_outcome(std::vector<std::pair<Rational, const Effect*> >& os,
                        const Rational* p, const Effect& effect) {
  if (!requirements->probabilistic_effects) {
    yywarning("assuming `:probabilistic-effects' requirement");
    requirements->probabilistic_effects = true;
  }
  if (*p < 0 || *p > 1) {
    yyerror("outcome probability needs to be in the interval [0,1]");
  }
  os.push_back(std::make_pair(*p, &effect));
  delete p;
}


/* Creates a probabilistic effect. */
static const Effect*
make_prob_effect(const std::vector<std::pair<Rational, const Effect*> >* os) {
  Rational psum = 0;
  for (size_t i = 0; i < os->size(); i++) {
    psum = psum + (*os)[i].first;
  }
  if (psum > 1) {
    yyerror("effect outcome probabilities add up to more than 1");
    delete os;
    return &Effect::EMPTY;
  } else {
    const Effect& peff = ProbabilisticEffect::make(*os);
    delete os;
    return &peff;
  }
}


/* Creates an add effect. */
static const Effect* make_add_effect(const Atom& atom) {
  PredicateTable::make_dynamic(atom.predicate());
  return new AddEffect(atom);
}


/* Creates a delete effect. */
static const Effect* make_delete_effect(const Atom& atom) {
  PredicateTable::make_dynamic(atom.predicate());
  return new DeleteEffect(atom);
}


/* Creates an assign update effect. */
static const Effect* make_assign_effect(const Fluent& fluent,
                                        const Expression& expr) {
  if (requirements->rewards && fluent.function() == reward_function) {
    yyerror("only constant reward increments/decrements allowed");
  } else {
    require_fluents();
  }
  effect_fluent = false;
  FunctionTable::make_dynamic(fluent.function());
  return &UpdateEffect::make(*new Assign(fluent, expr));
}


/* Creates a scale-up update effect. */
static const Effect* make_scale_up_effect(const Fluent& fluent,
                                          const Expression& expr) {
  if (requirements->rewards && fluent.function() == reward_function) {
    yyerror("only constant reward increments/decrements allowed");
  } else {
    require_fluents();
  }
  effect_fluent = false;
  FunctionTable::make_dynamic(fluent.function());
  return &UpdateEffect::make(*new ScaleUp(fluent, expr));
}


/* Creates a scale-down update effect. */
static const Effect* make_scale_down_effect(const Fluent& fluent,
                                            const Expression& expr) {
  if (requirements->rewards && fluent.function() == reward_function) {
    yyerror("only constant reward increments/decrements allowed");
  } else {
    require_fluents();
  }
  effect_fluent = false;
  FunctionTable::make_dynamic(fluent.function());
  return &UpdateEffect::make(*new ScaleDown(fluent, expr));
}


/* Creates an increase update effect. */
static const Effect* make_increase_effect(const Fluent& fluent,
                                          const Expression& expr) {
  if (requirements->rewards && fluent.function() == reward_function) {
    if (typeid(expr) != typeid(Value)) {
      yyerror("only constant reward increments/decrements allowed");
    }
  } else {
    require_fluents();
  }
  effect_fluent = false;
  FunctionTable::make_dynamic(fluent.function());
  return &UpdateEffect::make(*new Increase(fluent, expr));
}


/* Creates a decrease update effect. */
static const Effect* make_decrease_effect(const Fluent& fluent,
                                          const Expression& expr) {
  if (requirements->rewards && fluent.function() == reward_function) {
    if (typeid(expr) != typeid(Value)) {
      yyerror("only constant reward increments/decrements allowed");
    }
  } else {
    require_fluents();
  }
  effect_fluent = false;
  FunctionTable::make_dynamic(fluent.function());
  return &UpdateEffect::make(*new Decrease(fluent, expr));
}


/* Adds types, constants, or objects to the current domain or problem. */
static void add_names(const std::vector<const std::string*>* names,
                      const Type& type) {
  for (std::vector<const std::string*>::const_iterator si = names->begin();
       si != names->end(); si++) {
    const std::string* s = *si;
    if (name_kind == TYPE_KIND) {
      if (*s == TypeTable::OBJECT_NAME) {
        yywarning("ignoring declaration of reserved type `object'");
      } else if (*s == TypeTable::NUMBER_NAME) {
        yywarning("ignoring declaration of reserved type `number'");
      } else {
        const Type* t = domain->types().find_type(*s);
        if (t == 0) {
          t = &domain->types().add_type(*s);
        }
        if (!TypeTable::add_supertype(*t, type)) {
          yyerror("cyclic type hierarchy");
        }
      }
    } else if (name_kind == CONSTANT_KIND) {
      const Object* o = domain->terms().find_object(*s);
      if (o == 0) {
        domain->terms().add_object(*s, type);
      } else {
        TypeSet components;
        TypeTable::components(components, TermTable::type(*o));
        components.insert(type);
        TermTable::set_type(*o, make_type(components));
      }
    } else { /* name_kind == OBJECT_KIND */
      if (domain->terms().find_object(*s) != 0) {
        yywarning("ignoring declaration of object `" + *s
                  + "' previously declared as constant");
      } else {
        const Object* o = problem->terms().find_object(*s);
        if (o == 0) {
          problem->terms().add_object(*s, type);
        } else {
          TypeSet components;
          TypeTable::components(components, TermTable::type(*o));
          components.insert(type);
          TermTable::set_type(*o, make_type(components));
        }
      }
    }
    delete s;
  }
  delete names;
}


/* Adds variables to the current variable list. */
static void add_variables(const std::vector<const std::string*>* names,
                          const Type& type) {
  for (std::vector<const std::string*>::const_iterator si = names->begin();
       si != names->end(); si++) {
    const std::string* s = *si;
    if (predicate != 0) {
      if (!repeated_predicate) {
        PredicateTable::add_parameter(*predicate, type);
      }
    } else if (function != 0) {
      if (!repeated_function) {
        FunctionTable::add_parameter(*function, type);
      }
    } else {
      if (context.shallow_find(*s) != 0) {
        yyerror("repetition of parameter `" + *s + "'");
      } else if (context.find(*s) != 0) {
        yywarning("shadowing parameter `" + *s + "'");
      }
      Variable var = TermTable::add_variable(type);
      context.insert(*s, var);
      if (!quantified.empty()) {
        quantified.push_back(var);
      } else { /* action != 0 */
        action->add_parameter(var);
      }
    }
    delete s;
  }
  delete names;
}


/* Prepares for the parsing of an atomic state formula. */
static void prepare_atom(const std::string* name) {
  atom_predicate = domain->predicates().find_predicate(*name);
  if (atom_predicate == 0) {
    atom_predicate = &domain->predicates().add_predicate(*name);
    undeclared_atom_predicate = true;
    if (problem != 0) {
      yywarning("undeclared predicate `" + *name + "' used");
    } else {
      yywarning("implicit declaration of predicate `" + *name + "'");
    }
  } else {
    undeclared_atom_predicate = false;
  }
  term_parameters.clear();
  delete name;
}


/* Prepares for the parsing of a fluent. */
static void prepare_fluent(const std::string* name) {
  fluent_function = domain->functions().find_function(*name);
  if (fluent_function == 0) {
    fluent_function = &domain->functions().add_function(*name);
    undeclared_fluent_function = true;
    if (problem != 0) {
      yywarning("undeclared function `" + *name + "' used");
    } else {
      yywarning("implicit declaration of function `" + *name + "'");
    }
  } else {
    undeclared_fluent_function = false;
  }
  if (requirements->rewards && *name == "reward") {
    if (!effect_fluent && !metric_fluent) {
      yyerror("reserved function `reward' not allowed here");
    }
  } else if ((*name == "total-time" || *name == "goal-achieved")) {
    if (!metric_fluent) {
      yyerror("reserved function `" + *name + "' not allowed here");
    }
  } else {
    require_fluents();
  }
  term_parameters.clear();
  delete name;
}


/* Adds a term with the given name to the current atomic state formula. */
static void add_term(const std::string* name) {
  const Term& term = make_term(name);
  if (atom_predicate != 0) {
    size_t n = term_parameters.size();
    if (undeclared_atom_predicate) {
      PredicateTable::add_parameter(*atom_predicate, TermTable::type(term));
    } else {
      const TypeList& params = PredicateTable::parameters(*atom_predicate);
      if (params.size() > n
          && !TypeTable::subtype(TermTable::type(term), params[n])) {
        yyerror("type mismatch");
      }
    }
  } else if (fluent_function != 0) {
    size_t n = term_parameters.size();
    if (undeclared_fluent_function) {
      FunctionTable::add_parameter(*fluent_function, TermTable::type(term));
    } else {
      const TypeList& params = FunctionTable::parameters(*fluent_function);
      if (params.size() > n
          && !TypeTable::subtype(TermTable::type(term), params[n])) {
        yyerror("type mismatch");
      }
    }
  }
  term_parameters.push_back(term);
}


/* Creates the atomic formula just parsed. */
static const Atom* make_atom() {
  size_t n = term_parameters.size();
  if (PredicateTable::parameters(*atom_predicate).size() < n) {
    yyerror("too many parameters passed to predicate `"
            + PredicateTable::name(*atom_predicate) + "'");
  } else if (PredicateTable::parameters(*atom_predicate).size() > n) {
    yyerror("too few parameters passed to predicate `"
            + PredicateTable::name(*atom_predicate) + "'");
  }
  const Atom& atom = Atom::make(*atom_predicate, term_parameters);
  atom_predicate = 0;
  return &atom;
}


/* Creates the fluent just parsed. */
static const Fluent* make_fluent() {
  size_t n = term_parameters.size();
  if (FunctionTable::parameters(*fluent_function).size() < n) {
    yyerror("too many parameters passed to function `"
            + FunctionTable::name(*fluent_function) + "'");
  } else if (FunctionTable::parameters(*fluent_function).size() > n) {
    yyerror("too few parameters passed to function `"
            + FunctionTable::name(*fluent_function) + "'");
  }
  const Fluent& fluent = Fluent::make(*fluent_function, term_parameters);
  fluent_function = 0;
  return &fluent;
}


/* Creates a subtraction. */
static const Expression* make_subtraction(const Expression& term,
                                          const Expression* opt_term) {
  if (opt_term != 0) {
    return &Subtraction::make(term, *opt_term);
  } else {
    return &Subtraction::make(*new Value(0), term);
  }
}


/* Creates an atom or fluent for the given name to be used in an
   equality formula. */
static void make_eq_name(const std::string* name) {
  const Function* f = domain->functions().find_function(*name);
  if (f != 0) {
    prepare_fluent(name);
    eq_expr = make_fluent();
  } else {
    /* Assume this is a term. */
    eq_term = make_term(name);
    eq_expr = 0;
  }
}


/* Creates an equality formula. */
static const StateFormula* make_equality() {
  if (!requirements->equality) {
    yywarning("assuming `:equality' requirement");
    requirements->equality = true;
  }
  if (first_eq_expr != 0 && eq_expr != 0) {
    return &EqualTo::make(*first_eq_expr, *eq_expr);
  } else if (first_eq_expr == 0 && eq_expr == 0) {
    if (TypeTable::subtype(TermTable::type(first_eq_term),
                           TermTable::type(eq_term))
        || TypeTable::subtype(TermTable::type(eq_term),
                              TermTable::type(first_eq_term))) {
      return &Equality::make(first_eq_term, eq_term);
    } else {
      return &StateFormula::FALSE;
    }
  } else {
    yyerror("comparison of term and numeric expression");
    return &StateFormula::FALSE;
  }
}


/* Creates a negated formula. */
static const StateFormula* make_negation(const StateFormula& negand) {
  if (typeid(negand) == typeid(Atom)) {
    if (!requirements->negative_preconditions) {
      yywarning("assuming `:negative-preconditions' requirement");
      requirements->negative_preconditions = true;
    }
  } else if (typeid(negand) != typeid(Equality)
             && dynamic_cast<const Comparison*>(&negand) != 0) {
    require_disjunction();
  }
  return &Negation::make(negand);
}


/* Creates an implication. */
static const StateFormula* make_implication(const StateFormula& f1,
                                            const StateFormula& f2) {
  require_disjunction();
  return &(Negation::make(f1) || f2);
}


/* Prepares for the parsing of an existentially quantified formula. */
static void prepare_exists() {
  if (!requirements->existential_preconditions) {
    yywarning("assuming `:existential-preconditions' requirement");
    requirements->existential_preconditions = true;
  }
  context.push_frame();
  quantified.push_back(Term(0));
}


/* Prepares for the parsing of a universally quantified formula. */
static void prepare_forall() {
  if (!requirements->universal_preconditions) {
    yywarning("assuming `:universal-preconditions' requirement");
    requirements->universal_preconditions = true;
  }
  context.push_frame();
  quantified.push_back(Term(0));
}


/* Creates an existentially quantified formula. */
static const StateFormula* make_exists(const StateFormula& body) {
  context.pop_frame();
  size_t m = quantified.size() - 1;
  size_t n = m;
  while (quantified[n].variable()) {
    n--;
  }
  if (n < m) {
    VariableList parameters;
    for (size_t i = n + 1; i <= m; i++) {
      parameters.push_back(quantified[i].as_variable());
    }
    quantified.resize(n, Term(0));
    return &Exists::make(parameters, body);
  } else {
    quantified.pop_back();
    return &body;
  }
}


/* Creates a universally quantified formula. */
static const StateFormula* make_forall(const StateFormula& body) {
  context.pop_frame();
  size_t m = quantified.size() - 1;
  size_t n = m;
  while (quantified[n].variable()) {
    n--;
  }
  if (n < m) {
    VariableList parameters;
    for (size_t i = n + 1; i <= m; i++) {
      parameters.push_back(quantified[i].as_variable());
    }
    quantified.resize(n, Term(0));
    return &Forall::make(parameters, body);
  } else {
    quantified.pop_back();
    return &body;
  }
}


/* Sets the goal reward for the current problem. */
void set_goal_reward(const Expression& goal_reward) {
  if (!requirements->rewards) {
    yyerror("goal reward only allowed with the `:rewards' requirement");
  } else {
    FunctionTable::make_dynamic(reward_function);
    const Fluent& reward_fluent = Fluent::make(reward_function, TermList());
    problem->set_goal_reward(*new Increase(reward_fluent, goal_reward));
  }
}


/* Sets the default metric for the current problem. */
static void set_default_metric() {
  if (requirements->rewards) {
    problem->set_metric(Fluent::make(reward_function, TermList()));
  } else if (requirements->probabilistic_effects) {
    problem->set_metric(Fluent::make(domain->goal_achieved(), TermList()));
  } else {
    problem->set_metric(Fluent::make(domain->total_time(), TermList()), true);
  }
}
