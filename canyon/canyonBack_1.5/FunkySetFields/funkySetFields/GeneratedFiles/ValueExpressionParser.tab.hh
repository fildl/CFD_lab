/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison LALR(1) parsers in C++

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* C++ LALR(1) parser skeleton written by Akim Demaille.  */

#ifndef PARSER_HEADER_H
# define PARSER_HEADER_H

#include <string>
#include <iostream>
#include "stack.hh"

namespace ve
{
  class position;
  class location;
}

/* First part of user declarations.  */
#line 8 "ValueExpressionParser.yy"

#include <volFields.H>
#include <surfaceFields.H>
#include <fvcGrad.H>
#include <fvcCurl.H>
#include <fvcMagSqrGradGrad.H>
#include <fvcSnGrad.H>
#include <fvcDiv.H>
#include <fvcSurfaceIntegrate.H>
#include <fvcReconstruct.H>
#include <fvcAverage.H>
#include <surfaceInterpolate.H>
#include <fvcLaplacian.H>

#include <fvMatrix.H>

#include <functional>
#include <cmath>

class ValueExpressionDriver;


/* Line 303 of lalr1.cc.  */
#line 76 "ValueExpressionParser.tab.hh"

#include "location.hh"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
do {							\
  if (N)						\
    {							\
      (Current).begin = (Rhs)[1].begin;			\
      (Current).end   = (Rhs)[N].end;			\
    }							\
  else							\
    {							\
      (Current).begin = (Current).end = (Rhs)[0].end;	\
    }							\
} while (false)
#endif

namespace ve
{

  /// A Bison parser.
  class ValueExpressionParser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
#line 46 "ValueExpressionParser.yy"
{
    Foam::scalar val;
    Foam::vector *vec;
    Foam::string *name;
    Foam::string *vname;
    Foam::string *fsname;
    Foam::string *fvname;
    Foam::string *setname;
    Foam::string *zonename;
    Foam::volVectorField *vfield;
    Foam::volScalarField *sfield;
    Foam::surfaceScalarField *fsfield;
    Foam::surfaceVectorField *fvfield;
}
/* Line 303 of lalr1.cc.  */
#line 143 "ValueExpressionParser.tab.hh"
	;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;
    /// Tokens.
    struct token
    {
      /* Tokens.  */
   enum yytokentype {
     TOKEN_SID = 258,
     TOKEN_VID = 259,
     TOKEN_FSID = 260,
     TOKEN_FVID = 261,
     TOKEN_SETID = 262,
     TOKEN_ZONEID = 263,
     TOKEN_NUM = 264,
     TOKEN_VEC = 265,
     TOKEN_VECTOR = 273,
     TOKEN_TRUE = 274,
     TOKEN_FALSE = 275,
     TOKEN_pi = 276,
     TOKEN_rand = 277,
     TOKEN_id = 278,
     TOKEN_randNormal = 279,
     TOKEN_position = 280,
     TOKEN_fposition = 281,
     TOKEN_fprojection = 282,
     TOKEN_face = 283,
     TOKEN_area = 284,
     TOKEN_volume = 285,
     TOKEN_dist = 286,
     TOKEN_rdist = 287,
     TOKEN_set = 288,
     TOKEN_zone = 289,
     TOKEN_div = 290,
     TOKEN_grad = 291,
     TOKEN_curl = 292,
     TOKEN_snGrad = 293,
     TOKEN_magSqrGradGrad = 294,
     TOKEN_laplacian = 295,
     TOKEN_integrate = 296,
     TOKEN_sum = 297,
     TOKEN_interpolate = 298,
     TOKEN_average = 299,
     TOKEN_reconstruct = 300,
     TOKEN_surf = 301,
     TOKEN_deltaT = 302,
     TOKEN_time = 303,
     TOKEN_pow = 304,
     TOKEN_log = 305,
     TOKEN_exp = 306,
     TOKEN_mag = 307,
     TOKEN_sin = 308,
     TOKEN_cos = 309,
     TOKEN_tan = 310,
     TOKEN_min = 311,
     TOKEN_max = 312,
     TOKEN_sqr = 313,
     TOKEN_sqrt = 314,
     TOKEN_log10 = 315,
     TOKEN_asin = 316,
     TOKEN_acos = 317,
     TOKEN_atan = 318,
     TOKEN_sinh = 319,
     TOKEN_cosh = 320,
     TOKEN_tanh = 321,
     TOKEN_asinh = 322,
     TOKEN_acosh = 323,
     TOKEN_atanh = 324,
     TOKEN_erf = 325,
     TOKEN_erfc = 326,
     TOKEN_lgamma = 327,
     TOKEN_besselJ0 = 328,
     TOKEN_besselJ1 = 329,
     TOKEN_besselY0 = 330,
     TOKEN_besselY1 = 331,
     TOKEN_sign = 332,
     TOKEN_pos = 333,
     TOKEN_neg = 334,
     TOKEN_OR = 335,
     TOKEN_AND = 336,
     TOKEN_NEQ = 337,
     TOKEN_EQ = 338,
     TOKEN_GEQ = 339,
     TOKEN_LEQ = 340,
     TOKEN_NOT = 341,
     TOKEN_NEG = 342
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    ValueExpressionParser (ValueExpressionDriver& driver_yyarg);
    virtual ~ValueExpressionParser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);

  private:
    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Generate an error message.
    /// \param state   the state where the error occurred.
    /// \param tok     the look-ahead token.
    virtual std::string yysyntax_error_ (int yystate, int tok);

#if YYDEBUG
    /// \brief Report a symbol value on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_value_print_ (int yytype,
					 const semantic_type* yyvaluep,
					 const location_type* yylocationp);
    /// \brief Report a symbol on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_print_ (int yytype,
				   const semantic_type* yyvaluep,
				   const location_type* yylocationp);
#endif /* ! YYDEBUG */


    /// State numbers.
    typedef int state_type;
    /// State stack type.
    typedef stack<state_type>    state_stack_type;
    /// Semantic value stack type.
    typedef stack<semantic_type> semantic_stack_type;
    /// location stack type.
    typedef stack<location_type> location_stack_type;

    /// The state stack.
    state_stack_type yystate_stack_;
    /// The semantic value stack.
    semantic_stack_type yysemantic_stack_;
    /// The location stack.
    location_stack_type yylocation_stack_;

    /// Internal symbol numbers.
    typedef unsigned char token_number_type;
    /* Tables.  */
    /// For a state, the index in \a yytable_ of its portion.
    static const short int yypact_[];
    static const short int yypact_ninf_;

    /// For a state, default rule to reduce.
    /// Unless\a  yytable_ specifies something else to do.
    /// Zero means the default is an error.
    static const unsigned char yydefact_[];

    static const short int yypgoto_[];
    static const short int yydefgoto_[];

    /// What to do in a state.
    /// \a yytable_[yypact_[s]]: what to do in state \a s.
    /// - if positive, shift that token.
    /// - if negative, reduce the rule which number is the opposite.
    /// - if zero, do what YYDEFACT says.
    static const unsigned short int yytable_[];
    static const signed char yytable_ninf_;

    static const short int yycheck_[];

    /// For a state, its accessing symbol.
    static const unsigned char yystos_[];

    /// For a rule, its LHS.
    static const unsigned char yyr1_[];
    /// For a rule, its RHS length.
    static const unsigned char yyr2_[];

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif

#if YYERROR_VERBOSE
    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    virtual std::string yytnamerr_ (const char *n);
#endif

#if YYDEBUG
    /// A type to store symbol numbers and -1.
    typedef signed char rhs_number_type;
    /// A `-1'-separated list of the rules' RHS.
    static const rhs_number_type yyrhs_[];
    /// For each rule, the index of the first RHS symbol in \a yyrhs_.
    static const unsigned short int yyprhs_[];
    /// For each rule, its source line number.
    static const unsigned short int yyrline_[];
    /// For each scanner token number, its symbol number.
    static const unsigned short int yytoken_number_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();
#endif

    /// Convert a scanner token number \a t to a symbol number.
    token_number_type yytranslate_ (int t);

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg        Why this token is reclaimed.
    /// \param yytype       The symbol type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    inline void yydestruct_ (const char* yymsg,
			     int yytype,
			     semantic_type* yyvaluep,
			     location_type* yylocationp);

    /// Pop \a n symbols the three stacks.
    inline void yypop_ (unsigned int n = 1);

    /* Constants.  */
    static const int yyeof_;
    /* LAST_ -- Last index in TABLE_.  */
    static const int yylast_;
    static const int yynnts_;
    static const int yyempty_;
    static const int yyfinal_;
    static const int yyterror_;
    static const int yyerrcode_;
    static const int yyntokens_;
    static const unsigned int yyuser_token_number_max_;
    static const token_number_type yyundef_token_;

    /* Debugging.  */
    int yydebug_;
    std::ostream* yycdebug_;


    /* User arguments.  */
    ValueExpressionDriver& driver;
  };
}


#endif /* ! defined PARSER_HEADER_H */
