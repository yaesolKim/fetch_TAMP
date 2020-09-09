/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 272 "/home/glab/fetch_TAMP/src/rosplan/rosplan_dependencies/ppddl_parser/src/PPDDLParser/parser.yy" /* yacc.c:1909  */

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

#line 140 "/home/glab/fetch_TAMP/build/rosplan_dependencies/ppddl_parser.tab.hh" /* yacc.c:1909  */
};

typedef union PPDDL_STYPE PPDDL_STYPE;
# define PPDDL_STYPE_IS_TRIVIAL 1
# define PPDDL_STYPE_IS_DECLARED 1
#endif


extern PPDDL_STYPE ppddl_lval;

int ppddl_parse (void);

#endif /* !YY_PPDDL_HOME_GLAB_FETCH_TAMP_BUILD_ROSPLAN_DEPENDENCIES_PPDDL_PARSER_TAB_HH_INCLUDED  */
