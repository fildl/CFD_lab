/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++

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

// Take the name prefix into account.
#define yylex   velex

#include "ValueExpressionParser.tab.hh"

/* User implementation prologue.  */
#line 61 "ValueExpressionParser.yy"

#include "ValueExpressionDriver.H"
#include "ValueExpressionDriverLogicalTemplates.H"


/* Line 317 of lalr1.cc.  */
#line 49 "ValueExpressionParser.tab.cc"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG							\
  for (bool yydebugcond_ = yydebug_; yydebugcond_; yydebugcond_ = false)	\
    (*yycdebug_)

/* Enable debugging if requested.  */
#if YYDEBUG

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab

namespace ve
{
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  ValueExpressionParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  ValueExpressionParser::ValueExpressionParser (ValueExpressionDriver& driver_yyarg)
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
      driver (driver_yyarg)
  {
  }

  ValueExpressionParser::~ValueExpressionParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  ValueExpressionParser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
        case 3: /* "\"scalarID\"" */
#line 168 "ValueExpressionParser.yy"
	{ debug_stream () << *(yyvaluep->name); };
#line 179 "ValueExpressionParser.tab.cc"
	break;
      case 4: /* "\"vectorID\"" */
#line 168 "ValueExpressionParser.yy"
	{ debug_stream () << *(yyvaluep->vname); };
#line 184 "ValueExpressionParser.tab.cc"
	break;
      case 5: /* "\"faceScalarID\"" */
#line 168 "ValueExpressionParser.yy"
	{ debug_stream () << *(yyvaluep->fsname); };
#line 189 "ValueExpressionParser.tab.cc"
	break;
      case 6: /* "\"faceVectorID\"" */
#line 168 "ValueExpressionParser.yy"
	{ debug_stream () << *(yyvaluep->fvname); };
#line 194 "ValueExpressionParser.tab.cc"
	break;
      case 7: /* "\"cellSetID\"" */
#line 168 "ValueExpressionParser.yy"
	{ debug_stream () << *(yyvaluep->setname); };
#line 199 "ValueExpressionParser.tab.cc"
	break;
      case 8: /* "\"cellZoneID\"" */
#line 168 "ValueExpressionParser.yy"
	{ debug_stream () << *(yyvaluep->zonename); };
#line 204 "ValueExpressionParser.tab.cc"
	break;
      case 9: /* "\"number\"" */
#line 171 "ValueExpressionParser.yy"
	{ debug_stream () << (yyvaluep->val); };
#line 209 "ValueExpressionParser.tab.cc"
	break;
      case 10: /* "\"vector\"" */
#line 169 "ValueExpressionParser.yy"
	{ Foam::OStringStream buff; buff << *(yyvaluep->vec); debug_stream () << buff.str().c_str(); };
#line 214 "ValueExpressionParser.tab.cc"
	break;
      case 11: /* "\"sexpression\"" */
#line 171 "ValueExpressionParser.yy"
	{ debug_stream () << (yyvaluep->val); };
#line 219 "ValueExpressionParser.tab.cc"
	break;
      case 12: /* "\"expression\"" */
#line 172 "ValueExpressionParser.yy"
	{ debug_stream () << (yyvaluep->sfield)->name().c_str(); };
#line 224 "ValueExpressionParser.tab.cc"
	break;
      case 13: /* "\"lexpression\"" */
#line 172 "ValueExpressionParser.yy"
	{ debug_stream () << (yyvaluep->sfield)->name().c_str(); };
#line 229 "ValueExpressionParser.tab.cc"
	break;
      case 14: /* "\"flexpression\"" */
#line 172 "ValueExpressionParser.yy"
	{ debug_stream () << (yyvaluep->fsfield)->name().c_str(); };
#line 234 "ValueExpressionParser.tab.cc"
	break;
      case 15: /* "\"vexpression\"" */
#line 172 "ValueExpressionParser.yy"
	{ debug_stream () << (yyvaluep->vfield)->name().c_str(); };
#line 239 "ValueExpressionParser.tab.cc"
	break;
      case 16: /* "\"fsexpression\"" */
#line 172 "ValueExpressionParser.yy"
	{ debug_stream () << (yyvaluep->fsfield)->name().c_str(); };
#line 244 "ValueExpressionParser.tab.cc"
	break;
      case 17: /* "\"fvexpression\"" */
#line 172 "ValueExpressionParser.yy"
	{ debug_stream () << (yyvaluep->fvfield)->name().c_str(); };
#line 249 "ValueExpressionParser.tab.cc"
	break;
       default:
	  break;
      }
  }


  void
  ValueExpressionParser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif /* ! YYDEBUG */

  void
  ValueExpressionParser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 3: /* "\"scalarID\"" */
#line 170 "ValueExpressionParser.yy"
	{ delete (yyvaluep->name); };
#line 284 "ValueExpressionParser.tab.cc"
	break;
      case 4: /* "\"vectorID\"" */
#line 170 "ValueExpressionParser.yy"
	{ delete (yyvaluep->vname); };
#line 289 "ValueExpressionParser.tab.cc"
	break;
      case 5: /* "\"faceScalarID\"" */
#line 170 "ValueExpressionParser.yy"
	{ delete (yyvaluep->fsname); };
#line 294 "ValueExpressionParser.tab.cc"
	break;
      case 6: /* "\"faceVectorID\"" */
#line 170 "ValueExpressionParser.yy"
	{ delete (yyvaluep->fvname); };
#line 299 "ValueExpressionParser.tab.cc"
	break;
      case 7: /* "\"cellSetID\"" */
#line 170 "ValueExpressionParser.yy"
	{ delete (yyvaluep->setname); };
#line 304 "ValueExpressionParser.tab.cc"
	break;
      case 8: /* "\"cellZoneID\"" */
#line 170 "ValueExpressionParser.yy"
	{ delete (yyvaluep->zonename); };
#line 309 "ValueExpressionParser.tab.cc"
	break;
      case 10: /* "\"vector\"" */
#line 170 "ValueExpressionParser.yy"
	{ delete (yyvaluep->vec); };
#line 314 "ValueExpressionParser.tab.cc"
	break;
      case 12: /* "\"expression\"" */
#line 170 "ValueExpressionParser.yy"
	{ delete (yyvaluep->sfield); };
#line 319 "ValueExpressionParser.tab.cc"
	break;
      case 13: /* "\"lexpression\"" */
#line 170 "ValueExpressionParser.yy"
	{ delete (yyvaluep->sfield); };
#line 324 "ValueExpressionParser.tab.cc"
	break;
      case 14: /* "\"flexpression\"" */
#line 170 "ValueExpressionParser.yy"
	{ delete (yyvaluep->fsfield); };
#line 329 "ValueExpressionParser.tab.cc"
	break;
      case 15: /* "\"vexpression\"" */
#line 170 "ValueExpressionParser.yy"
	{ delete (yyvaluep->vfield); };
#line 334 "ValueExpressionParser.tab.cc"
	break;
      case 16: /* "\"fsexpression\"" */
#line 170 "ValueExpressionParser.yy"
	{ delete (yyvaluep->fsfield); };
#line 339 "ValueExpressionParser.tab.cc"
	break;
      case 17: /* "\"fvexpression\"" */
#line 170 "ValueExpressionParser.yy"
	{ delete (yyvaluep->fvfield); };
#line 344 "ValueExpressionParser.tab.cc"
	break;

	default:
	  break;
      }
  }

  void
  ValueExpressionParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

  std::ostream&
  ValueExpressionParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  ValueExpressionParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  ValueExpressionParser::debug_level_type
  ValueExpressionParser::debug_level () const
  {
    return yydebug_;
  }

  void
  ValueExpressionParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }


  int
  ValueExpressionParser::parse ()
  {
    /// Look-ahead and look-ahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the look-ahead.
    semantic_type yylval;
    /// Location of the look-ahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    #line 37 "ValueExpressionParser.yy"
{
	     // Initialize the initial location.
	     //     @$.begin.filename = @$.end.filename = &driver.file;
}
  /* Line 555 of yacc.c.  */
#line 426 "ValueExpressionParser.tab.cc"
    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;
    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without look-ahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a look-ahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc, driver);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Accept?  */
    if (yyn == yyfinal_)
      goto yyacceptlab;

    /* Shift the look-ahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted unless it is eof.  */
    if (yychar != yyeof_)
      yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:
#line 178 "ValueExpressionParser.yy"
    { driver.setScalarResult((yysemantic_stack_[(1) - (1)].sfield));  ;}
    break;

  case 3:
#line 179 "ValueExpressionParser.yy"
    { driver.setVectorResult((yysemantic_stack_[(1) - (1)].vfield));  ;}
    break;

  case 4:
#line 180 "ValueExpressionParser.yy"
    { driver.setLogicalResult((yysemantic_stack_[(1) - (1)].sfield)); ;}
    break;

  case 5:
#line 183 "ValueExpressionParser.yy"
    { (yyval.vfield) = (yysemantic_stack_[(1) - (1)].vfield); ;}
    break;

  case 6:
#line 184 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(*(yysemantic_stack_[(3) - (1)].vfield) + *(yysemantic_stack_[(3) - (3)].vfield)); delete (yysemantic_stack_[(3) - (1)].vfield); delete (yysemantic_stack_[(3) - (3)].vfield); ;}
    break;

  case 7:
#line 185 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(*(yysemantic_stack_[(3) - (1)].sfield) * *(yysemantic_stack_[(3) - (3)].vfield)); delete (yysemantic_stack_[(3) - (1)].sfield); delete (yysemantic_stack_[(3) - (3)].vfield); ;}
    break;

  case 8:
#line 186 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(*(yysemantic_stack_[(3) - (1)].vfield) * *(yysemantic_stack_[(3) - (3)].sfield)); delete (yysemantic_stack_[(3) - (1)].vfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 9:
#line 187 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(*(yysemantic_stack_[(3) - (1)].vfield) / *(yysemantic_stack_[(3) - (3)].sfield)); delete (yysemantic_stack_[(3) - (1)].vfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 10:
#line 188 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(*(yysemantic_stack_[(3) - (1)].vfield) ^ *(yysemantic_stack_[(3) - (3)].vfield)); delete (yysemantic_stack_[(3) - (1)].vfield); delete (yysemantic_stack_[(3) - (3)].vfield); ;}
    break;

  case 11:
#line 189 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(*(yysemantic_stack_[(3) - (1)].vfield) - *(yysemantic_stack_[(3) - (3)].vfield)); delete (yysemantic_stack_[(3) - (1)].vfield); delete (yysemantic_stack_[(3) - (3)].vfield);;}
    break;

  case 12:
#line 190 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(-*(yysemantic_stack_[(2) - (2)].vfield)); delete (yysemantic_stack_[(2) - (2)].vfield); ;}
    break;

  case 13:
#line 191 "ValueExpressionParser.yy"
    { (yyval.vfield) = (yysemantic_stack_[(3) - (2)].vfield); ;}
    break;

  case 14:
#line 192 "ValueExpressionParser.yy"
    { (yyval.vfield) = driver.doConditional((yysemantic_stack_[(5) - (1)].sfield),(yysemantic_stack_[(5) - (3)].vfield),(yysemantic_stack_[(5) - (5)].vfield),driver.makeVectorField(Foam::vector())); delete (yysemantic_stack_[(5) - (1)].sfield); delete (yysemantic_stack_[(5) - (3)].vfield); delete (yysemantic_stack_[(5) - (5)].vfield); ;}
    break;

  case 15:
#line 193 "ValueExpressionParser.yy"
    { (yyval.vfield) = driver.makePositionField(); ;}
    break;

  case 16:
#line 194 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(Foam::fvc::laplacian(*(yysemantic_stack_[(6) - (3)].fsfield),*(yysemantic_stack_[(6) - (5)].vfield))); delete (yysemantic_stack_[(6) - (3)].fsfield); delete (yysemantic_stack_[(6) - (5)].vfield); ;}
    break;

  case 17:
#line 195 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(Foam::fvc::average(*(yysemantic_stack_[(4) - (3)].fvfield))); delete (yysemantic_stack_[(4) - (3)].fvfield); ;}
    break;

  case 18:
#line 196 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(Foam::fvc::surfaceIntegrate(*(yysemantic_stack_[(4) - (3)].fvfield))); delete (yysemantic_stack_[(4) - (3)].fvfield); ;}
    break;

  case 19:
#line 197 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(Foam::fvc::surfaceSum(*(yysemantic_stack_[(4) - (3)].fvfield))); delete (yysemantic_stack_[(4) - (3)].fvfield); ;}
    break;

  case 20:
#line 198 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(Foam::fvc::grad(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 21:
#line 199 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(Foam::fvc::reconstruct(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 22:
#line 200 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(Foam::fvc::curl(*(yysemantic_stack_[(4) - (3)].vfield))); delete (yysemantic_stack_[(4) - (3)].vfield); ;}
    break;

  case 23:
#line 201 "ValueExpressionParser.yy"
    { (yyval.vfield) = new Foam::volVectorField(Foam::fvc::div(*(yysemantic_stack_[(6) - (3)].fsfield),*(yysemantic_stack_[(6) - (5)].vfield))); delete (yysemantic_stack_[(6) - (3)].fsfield); delete (yysemantic_stack_[(6) - (5)].vfield); ;}
    break;

  case 24:
#line 202 "ValueExpressionParser.yy"
    { (yyval.vfield)=driver.getField<Foam::volVectorField>(*(yysemantic_stack_[(1) - (1)].vname)); ;}
    break;

  case 25:
#line 205 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.makeSurfaceScalarField((yysemantic_stack_[(4) - (3)].val)); ;}
    break;

  case 26:
#line 206 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(*(yysemantic_stack_[(3) - (1)].fsfield) + *(yysemantic_stack_[(3) - (3)].fsfield)); delete (yysemantic_stack_[(3) - (1)].fsfield); delete (yysemantic_stack_[(3) - (3)].fsfield); ;}
    break;

  case 27:
#line 207 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(*(yysemantic_stack_[(3) - (1)].fsfield) * *(yysemantic_stack_[(3) - (3)].fsfield)); delete (yysemantic_stack_[(3) - (1)].fsfield); delete (yysemantic_stack_[(3) - (3)].fsfield); ;}
    break;

  case 28:
#line 208 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(*(yysemantic_stack_[(3) - (1)].fvfield) & *(yysemantic_stack_[(3) - (3)].fvfield)); delete (yysemantic_stack_[(3) - (1)].fvfield); delete (yysemantic_stack_[(3) - (3)].fvfield); ;}
    break;

  case 29:
#line 209 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(*(yysemantic_stack_[(3) - (1)].fsfield) / *(yysemantic_stack_[(3) - (3)].fsfield)); delete (yysemantic_stack_[(3) - (1)].fsfield); delete (yysemantic_stack_[(3) - (3)].fsfield); ;}
    break;

  case 30:
#line 210 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(*(yysemantic_stack_[(3) - (1)].fsfield) - *(yysemantic_stack_[(3) - (3)].fsfield)); delete (yysemantic_stack_[(3) - (1)].fsfield); delete (yysemantic_stack_[(3) - (3)].fsfield);;}
    break;

  case 31:
#line 211 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::pow(*(yysemantic_stack_[(6) - (3)].fsfield), (yysemantic_stack_[(6) - (5)].val))); delete (yysemantic_stack_[(6) - (3)].fsfield); ;}
    break;

  case 32:
#line 212 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::log(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 33:
#line 213 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::exp(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 34:
#line 214 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::sqr(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 35:
#line 215 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::sqrt(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 36:
#line 216 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::sin(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 37:
#line 217 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::cos(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 38:
#line 218 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::tan(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 39:
#line 219 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::log10(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 40:
#line 220 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::asin(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 41:
#line 221 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::acos(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 42:
#line 222 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::atan(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 43:
#line 223 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::sinh(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 44:
#line 224 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::cosh(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 45:
#line 225 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::tanh(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 46:
#line 226 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::asinh(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 47:
#line 227 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::acosh(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 48:
#line 228 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::atanh(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 49:
#line 229 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::erf(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 50:
#line 230 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::erfc(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 51:
#line 231 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::lgamma(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 52:
#line 232 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::j0(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 53:
#line 233 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::j1(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 54:
#line 234 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::y0(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 55:
#line 235 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::y1(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 56:
#line 236 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::sign(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 57:
#line 237 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::pos(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 58:
#line 238 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::neg(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 59:
#line 239 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.makeSurfaceScalarField(Foam::min(*(yysemantic_stack_[(4) - (3)].fsfield)).value()); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 60:
#line 240 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.makeSurfaceScalarField(Foam::max(*(yysemantic_stack_[(4) - (3)].fsfield)).value()); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 61:
#line 241 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(-*(yysemantic_stack_[(2) - (2)].fsfield)); delete (yysemantic_stack_[(2) - (2)].fsfield); ;}
    break;

  case 62:
#line 242 "ValueExpressionParser.yy"
    { (yyval.fsfield) = (yysemantic_stack_[(3) - (2)].fsfield); ;}
    break;

  case 63:
#line 243 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField((yysemantic_stack_[(3) - (1)].fvfield)->component(0)); delete (yysemantic_stack_[(3) - (1)].fvfield); ;}
    break;

  case 64:
#line 244 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField((yysemantic_stack_[(3) - (1)].fvfield)->component(1)); delete (yysemantic_stack_[(3) - (1)].fvfield); ;}
    break;

  case 65:
#line 245 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField((yysemantic_stack_[(3) - (1)].fvfield)->component(2)); delete (yysemantic_stack_[(3) - (1)].fvfield); ;}
    break;

  case 66:
#line 246 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.doConditional((yysemantic_stack_[(5) - (1)].fsfield),(yysemantic_stack_[(5) - (3)].fsfield),(yysemantic_stack_[(5) - (5)].fsfield),driver.makeSurfaceScalarField(0.)); delete (yysemantic_stack_[(5) - (1)].fsfield); delete (yysemantic_stack_[(5) - (3)].fsfield); delete (yysemantic_stack_[(5) - (5)].fsfield); ;}
    break;

  case 67:
#line 247 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::mag(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 68:
#line 248 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::mag(*(yysemantic_stack_[(4) - (3)].fvfield))); delete (yysemantic_stack_[(4) - (3)].fvfield); ;}
    break;

  case 69:
#line 249 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.makeAreaField(); ;}
    break;

  case 70:
#line 250 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::fvc::snGrad(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 71:
#line 251 "ValueExpressionParser.yy"
    { (yyval.fsfield) = new Foam::surfaceScalarField(Foam::fvc::interpolate(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 72:
#line 252 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.getField<Foam::surfaceScalarField>(*(yysemantic_stack_[(1) - (1)].fsname)); ;}
    break;

  case 73:
#line 255 "ValueExpressionParser.yy"
    { (yyval.fvfield) = (yysemantic_stack_[(1) - (1)].fvfield); ;}
    break;

  case 74:
#line 256 "ValueExpressionParser.yy"
    { (yyval.fvfield) = new Foam::surfaceVectorField(*(yysemantic_stack_[(3) - (1)].fvfield) + *(yysemantic_stack_[(3) - (3)].fvfield)); delete (yysemantic_stack_[(3) - (1)].fvfield); delete (yysemantic_stack_[(3) - (3)].fvfield); ;}
    break;

  case 75:
#line 257 "ValueExpressionParser.yy"
    { (yyval.fvfield) = new Foam::surfaceVectorField(*(yysemantic_stack_[(3) - (1)].fsfield) * *(yysemantic_stack_[(3) - (3)].fvfield)); delete (yysemantic_stack_[(3) - (1)].fsfield); delete (yysemantic_stack_[(3) - (3)].fvfield); ;}
    break;

  case 76:
#line 258 "ValueExpressionParser.yy"
    { (yyval.fvfield) = new Foam::surfaceVectorField(*(yysemantic_stack_[(3) - (1)].fvfield) * *(yysemantic_stack_[(3) - (3)].fsfield)); delete (yysemantic_stack_[(3) - (1)].fvfield); delete (yysemantic_stack_[(3) - (3)].fsfield); ;}
    break;

  case 77:
#line 259 "ValueExpressionParser.yy"
    { (yyval.fvfield) = new Foam::surfaceVectorField(*(yysemantic_stack_[(3) - (1)].fvfield) ^ *(yysemantic_stack_[(3) - (3)].fvfield)); delete (yysemantic_stack_[(3) - (1)].fvfield); delete (yysemantic_stack_[(3) - (3)].fvfield); ;}
    break;

  case 78:
#line 260 "ValueExpressionParser.yy"
    { (yyval.fvfield) = new Foam::surfaceVectorField(*(yysemantic_stack_[(3) - (1)].fvfield) / *(yysemantic_stack_[(3) - (3)].fsfield)); delete (yysemantic_stack_[(3) - (1)].fvfield); delete (yysemantic_stack_[(3) - (3)].fsfield); ;}
    break;

  case 79:
#line 261 "ValueExpressionParser.yy"
    { (yyval.fvfield) = new Foam::surfaceVectorField(*(yysemantic_stack_[(3) - (1)].fvfield) - *(yysemantic_stack_[(3) - (3)].fvfield)); delete (yysemantic_stack_[(3) - (1)].fvfield); delete (yysemantic_stack_[(3) - (3)].fvfield);;}
    break;

  case 80:
#line 262 "ValueExpressionParser.yy"
    { (yyval.fvfield) = new Foam::surfaceVectorField(-*(yysemantic_stack_[(2) - (2)].fvfield)); delete (yysemantic_stack_[(2) - (2)].fvfield); ;}
    break;

  case 81:
#line 263 "ValueExpressionParser.yy"
    { (yyval.fvfield) = (yysemantic_stack_[(3) - (2)].fvfield); ;}
    break;

  case 82:
#line 264 "ValueExpressionParser.yy"
    { (yyval.fvfield) = driver.doConditional((yysemantic_stack_[(5) - (1)].fsfield),(yysemantic_stack_[(5) - (3)].fvfield),(yysemantic_stack_[(5) - (5)].fvfield),driver.makeSurfaceVectorField(Foam::vector::zero)); delete (yysemantic_stack_[(5) - (1)].fsfield); delete (yysemantic_stack_[(5) - (3)].fvfield); delete (yysemantic_stack_[(5) - (5)].fvfield); ;}
    break;

  case 83:
#line 265 "ValueExpressionParser.yy"
    { (yyval.fvfield) = driver.makeFacePositionField(); ;}
    break;

  case 84:
#line 266 "ValueExpressionParser.yy"
    { (yyval.fvfield) = driver.makeFaceProjectionField(); ;}
    break;

  case 85:
#line 267 "ValueExpressionParser.yy"
    { (yyval.fvfield) = driver.makeFaceField(); ;}
    break;

  case 86:
#line 268 "ValueExpressionParser.yy"
    { (yyval.fvfield) = new Foam::surfaceVectorField(Foam::fvc::snGrad(*(yysemantic_stack_[(4) - (3)].vfield))); delete (yysemantic_stack_[(4) - (3)].vfield); ;}
    break;

  case 87:
#line 269 "ValueExpressionParser.yy"
    { (yyval.fvfield) = new Foam::surfaceVectorField(Foam::fvc::interpolate(*(yysemantic_stack_[(4) - (3)].vfield))); delete (yysemantic_stack_[(4) - (3)].vfield); ;}
    break;

  case 88:
#line 270 "ValueExpressionParser.yy"
    { (yyval.fvfield) = driver.getField<Foam::surfaceVectorField>(*(yysemantic_stack_[(1) - (1)].fvname)); ;}
    break;

  case 89:
#line 273 "ValueExpressionParser.yy"
    { (yyval.val) = (yysemantic_stack_[(1) - (1)].val); ;}
    break;

  case 90:
#line 274 "ValueExpressionParser.yy"
    { (yyval.val) = -(yysemantic_stack_[(2) - (2)].val); ;}
    break;

  case 91:
#line 277 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeScalarField((yysemantic_stack_[(1) - (1)].val)); ;}
    break;

  case 92:
#line 278 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(*(yysemantic_stack_[(3) - (1)].sfield) + *(yysemantic_stack_[(3) - (3)].sfield)); delete (yysemantic_stack_[(3) - (1)].sfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 93:
#line 279 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(*(yysemantic_stack_[(3) - (1)].sfield) - *(yysemantic_stack_[(3) - (3)].sfield)); delete (yysemantic_stack_[(3) - (1)].sfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 94:
#line 280 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(*(yysemantic_stack_[(3) - (1)].sfield) * *(yysemantic_stack_[(3) - (3)].sfield)); delete (yysemantic_stack_[(3) - (1)].sfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 95:
#line 281 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeModuloField(*(yysemantic_stack_[(3) - (1)].sfield),*(yysemantic_stack_[(3) - (3)].sfield)); delete (yysemantic_stack_[(3) - (1)].sfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 96:
#line 282 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(*(yysemantic_stack_[(3) - (1)].sfield) / *(yysemantic_stack_[(3) - (3)].sfield)); delete (yysemantic_stack_[(3) - (1)].sfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 97:
#line 283 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::pow(*(yysemantic_stack_[(6) - (3)].sfield), (yysemantic_stack_[(6) - (5)].val))); delete (yysemantic_stack_[(6) - (3)].sfield); ;}
    break;

  case 98:
#line 284 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::log(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 99:
#line 285 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::exp(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 100:
#line 286 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(*(yysemantic_stack_[(3) - (1)].vfield) & *(yysemantic_stack_[(3) - (3)].vfield)); delete (yysemantic_stack_[(3) - (1)].vfield); delete (yysemantic_stack_[(3) - (3)].vfield);;}
    break;

  case 101:
#line 287 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(-*(yysemantic_stack_[(2) - (2)].sfield)); delete (yysemantic_stack_[(2) - (2)].sfield); ;}
    break;

  case 102:
#line 288 "ValueExpressionParser.yy"
    { (yyval.sfield) = (yysemantic_stack_[(3) - (2)].sfield); ;}
    break;

  case 103:
#line 289 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::sqr(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 104:
#line 290 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::sqrt(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 105:
#line 291 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::sin(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 106:
#line 292 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::cos(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 107:
#line 293 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::tan(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 108:
#line 294 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::log10(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 109:
#line 295 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::asin(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 110:
#line 296 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::acos(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 111:
#line 297 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::atan(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 112:
#line 298 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::sinh(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 113:
#line 299 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::cosh(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 114:
#line 300 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::tanh(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 115:
#line 301 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::asinh(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 116:
#line 302 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::acosh(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 117:
#line 303 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::atanh(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 118:
#line 304 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::erf(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 119:
#line 305 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::erfc(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 120:
#line 306 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::lgamma(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 121:
#line 307 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::j0(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 122:
#line 308 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::j1(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 123:
#line 309 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::y0(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 124:
#line 310 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::y1(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 125:
#line 311 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::sign(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 126:
#line 312 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::pos(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 127:
#line 313 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::neg(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 128:
#line 314 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeScalarField(Foam::min(*(yysemantic_stack_[(4) - (3)].sfield)).value()); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 129:
#line 315 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeScalarField(Foam::max(*(yysemantic_stack_[(4) - (3)].sfield)).value()); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 130:
#line 316 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::mag(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 131:
#line 317 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::fvc::magSqrGradGrad(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 132:
#line 318 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::mag(*(yysemantic_stack_[(4) - (3)].vfield))); delete (yysemantic_stack_[(4) - (3)].vfield); ;}
    break;

  case 133:
#line 319 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::fvc::div(*(yysemantic_stack_[(4) - (3)].vfield))); delete (yysemantic_stack_[(4) - (3)].vfield); ;}
    break;

  case 134:
#line 320 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::fvc::div(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 135:
#line 321 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::fvc::div(*(yysemantic_stack_[(6) - (3)].fsfield),*(yysemantic_stack_[(6) - (5)].sfield))); delete (yysemantic_stack_[(6) - (3)].fsfield); delete (yysemantic_stack_[(6) - (5)].sfield); ;}
    break;

  case 136:
#line 322 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::fvc::laplacian(*(yysemantic_stack_[(4) - (3)].sfield))); delete (yysemantic_stack_[(4) - (3)].sfield); ;}
    break;

  case 137:
#line 323 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::fvc::laplacian(*(yysemantic_stack_[(6) - (3)].sfield),*(yysemantic_stack_[(6) - (5)].sfield))); delete (yysemantic_stack_[(6) - (3)].sfield); delete (yysemantic_stack_[(6) - (5)].sfield); ;}
    break;

  case 138:
#line 324 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::fvc::laplacian(*(yysemantic_stack_[(6) - (3)].fsfield),*(yysemantic_stack_[(6) - (5)].sfield))); delete (yysemantic_stack_[(6) - (3)].fsfield); delete (yysemantic_stack_[(6) - (5)].sfield); ;}
    break;

  case 139:
#line 325 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::fvc::average(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 140:
#line 326 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::fvc::surfaceIntegrate(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 141:
#line 327 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField(Foam::fvc::surfaceSum(*(yysemantic_stack_[(4) - (3)].fsfield))); delete (yysemantic_stack_[(4) - (3)].fsfield); ;}
    break;

  case 142:
#line 328 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField((yysemantic_stack_[(3) - (1)].vfield)->component(0)); delete (yysemantic_stack_[(3) - (1)].vfield); ;}
    break;

  case 143:
#line 329 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField((yysemantic_stack_[(3) - (1)].vfield)->component(1)); delete (yysemantic_stack_[(3) - (1)].vfield); ;}
    break;

  case 144:
#line 330 "ValueExpressionParser.yy"
    { (yyval.sfield) = new Foam::volScalarField((yysemantic_stack_[(3) - (1)].vfield)->component(2)); delete (yysemantic_stack_[(3) - (1)].vfield); ;}
    break;

  case 145:
#line 331 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.doConditional((yysemantic_stack_[(5) - (1)].sfield),(yysemantic_stack_[(5) - (3)].sfield),(yysemantic_stack_[(5) - (5)].sfield),driver.makeScalarField(0.)); delete (yysemantic_stack_[(5) - (1)].sfield); delete (yysemantic_stack_[(5) - (3)].sfield); delete (yysemantic_stack_[(5) - (5)].sfield); ;}
    break;

  case 146:
#line 332 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeScalarField(M_PI); ;}
    break;

  case 147:
#line 333 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeDistanceField(); ;}
    break;

  case 148:
#line 334 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeRDistanceField(*(yysemantic_stack_[(4) - (3)].vfield)); delete (yysemantic_stack_[(4) - (3)].vfield); ;}
    break;

  case 149:
#line 335 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeVolumeField(); ;}
    break;

  case 150:
#line 336 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeRandomField(); ;}
    break;

  case 151:
#line 337 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeGaussRandomField(); ;}
    break;

  case 152:
#line 338 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeCellIdField(); ;}
    break;

  case 153:
#line 339 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeScalarField(driver.runTime().deltaT().value()); ;}
    break;

  case 154:
#line 340 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeScalarField(driver.runTime().time().value()); ;}
    break;

  case 155:
#line 341 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.getField<Foam::volScalarField>(*(yysemantic_stack_[(1) - (1)].name)); ;}
    break;

  case 156:
#line 344 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeScalarField(1); ;}
    break;

  case 157:
#line 345 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeScalarField(0); ;}
    break;

  case 158:
#line 346 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeCellSetField(*(yysemantic_stack_[(4) - (3)].setname)); ;}
    break;

  case 159:
#line 347 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.makeCellZoneField(*(yysemantic_stack_[(4) - (3)].zonename)); ;}
    break;

  case 160:
#line 348 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.doCompare((yysemantic_stack_[(3) - (1)].sfield),std::less<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].sfield));  delete (yysemantic_stack_[(3) - (1)].sfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 161:
#line 349 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.doCompare((yysemantic_stack_[(3) - (1)].sfield),std::greater<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].sfield));  delete (yysemantic_stack_[(3) - (1)].sfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 162:
#line 350 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.doCompare((yysemantic_stack_[(3) - (1)].sfield),std::less_equal<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].sfield));  delete (yysemantic_stack_[(3) - (1)].sfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 163:
#line 351 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.doCompare((yysemantic_stack_[(3) - (1)].sfield),std::greater_equal<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].sfield));  delete (yysemantic_stack_[(3) - (1)].sfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 164:
#line 352 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.doCompare((yysemantic_stack_[(3) - (1)].sfield),std::equal_to<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].sfield));  delete (yysemantic_stack_[(3) - (1)].sfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 165:
#line 353 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.doCompare((yysemantic_stack_[(3) - (1)].sfield),std::not_equal_to<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].sfield));  delete (yysemantic_stack_[(3) - (1)].sfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 166:
#line 354 "ValueExpressionParser.yy"
    { (yyval.sfield) = (yysemantic_stack_[(3) - (2)].sfield); ;}
    break;

  case 167:
#line 355 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.doLogicalOp((yysemantic_stack_[(3) - (1)].sfield),std::logical_and<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].sfield));  delete (yysemantic_stack_[(3) - (1)].sfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 168:
#line 356 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.doLogicalOp((yysemantic_stack_[(3) - (1)].sfield),std::logical_or<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].sfield));  delete (yysemantic_stack_[(3) - (1)].sfield); delete (yysemantic_stack_[(3) - (3)].sfield); ;}
    break;

  case 169:
#line 357 "ValueExpressionParser.yy"
    { (yyval.sfield) = driver.doLogicalNot((yysemantic_stack_[(2) - (2)].sfield)); delete (yysemantic_stack_[(2) - (2)].sfield); ;}
    break;

  case 170:
#line 360 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.makeSurfaceScalarField(1); ;}
    break;

  case 171:
#line 361 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.makeSurfaceScalarField(0); ;}
    break;

  case 172:
#line 362 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.doCompare((yysemantic_stack_[(3) - (1)].fsfield),std::less<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].fsfield));  delete (yysemantic_stack_[(3) - (1)].fsfield); delete (yysemantic_stack_[(3) - (3)].fsfield); ;}
    break;

  case 173:
#line 363 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.doCompare((yysemantic_stack_[(3) - (1)].fsfield),std::greater<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].fsfield));  delete (yysemantic_stack_[(3) - (1)].fsfield); delete (yysemantic_stack_[(3) - (3)].fsfield); ;}
    break;

  case 174:
#line 364 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.doCompare((yysemantic_stack_[(3) - (1)].fsfield),std::less_equal<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].fsfield));  delete (yysemantic_stack_[(3) - (1)].fsfield); delete (yysemantic_stack_[(3) - (3)].fsfield); ;}
    break;

  case 175:
#line 365 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.doCompare((yysemantic_stack_[(3) - (1)].fsfield),std::greater_equal<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].fsfield));  delete (yysemantic_stack_[(3) - (1)].fsfield); delete (yysemantic_stack_[(3) - (3)].fsfield); ;}
    break;

  case 176:
#line 366 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.doCompare((yysemantic_stack_[(3) - (1)].fsfield),std::equal_to<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].fsfield));  delete (yysemantic_stack_[(3) - (1)].fsfield); delete (yysemantic_stack_[(3) - (3)].fsfield); ;}
    break;

  case 177:
#line 367 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.doCompare((yysemantic_stack_[(3) - (1)].fsfield),std::not_equal_to<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].fsfield));  delete (yysemantic_stack_[(3) - (1)].fsfield); delete (yysemantic_stack_[(3) - (3)].fsfield); ;}
    break;

  case 178:
#line 368 "ValueExpressionParser.yy"
    { (yyval.fsfield) = (yysemantic_stack_[(3) - (2)].fsfield); ;}
    break;

  case 179:
#line 369 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.doLogicalOp((yysemantic_stack_[(3) - (1)].fsfield),std::logical_and<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].fsfield));  delete (yysemantic_stack_[(3) - (1)].fsfield); delete (yysemantic_stack_[(3) - (3)].fsfield); ;}
    break;

  case 180:
#line 370 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.doLogicalOp((yysemantic_stack_[(3) - (1)].fsfield),std::logical_or<Foam::scalar>(),(yysemantic_stack_[(3) - (3)].fsfield));  delete (yysemantic_stack_[(3) - (1)].fsfield); delete (yysemantic_stack_[(3) - (3)].fsfield); ;}
    break;

  case 181:
#line 371 "ValueExpressionParser.yy"
    { (yyval.fsfield) = driver.doLogicalNot((yysemantic_stack_[(2) - (2)].fsfield)); delete (yysemantic_stack_[(2) - (2)].fsfield); ;}
    break;

  case 182:
#line 374 "ValueExpressionParser.yy"
    {     (yyval.vfield) = driver.makeVectorField((yysemantic_stack_[(8) - (3)].sfield),(yysemantic_stack_[(8) - (5)].sfield),(yysemantic_stack_[(8) - (7)].sfield));  delete (yysemantic_stack_[(8) - (3)].sfield); delete (yysemantic_stack_[(8) - (5)].sfield); delete (yysemantic_stack_[(8) - (7)].sfield);;}
    break;

  case 183:
#line 377 "ValueExpressionParser.yy"
    {     (yyval.fvfield) = driver.makeSurfaceVectorField((yysemantic_stack_[(8) - (3)].fsfield),(yysemantic_stack_[(8) - (5)].fsfield),(yysemantic_stack_[(8) - (7)].fsfield));  delete (yysemantic_stack_[(8) - (3)].fsfield); delete (yysemantic_stack_[(8) - (5)].fsfield); delete (yysemantic_stack_[(8) - (7)].fsfield);;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 1453 "ValueExpressionParser.tab.cc"
	default: break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse look-ahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    if (yyn == yyfinal_)
      goto yyacceptlab;

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the look-ahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		   &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyeof_ && yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  ValueExpressionParser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int ValueExpressionParser::yypact_ninf_ = -436;
  const short int
  ValueExpressionParser::yypact_[] =
  {
       673,  -436,  -436,  -436,   -92,  -436,  -436,  -436,   -87,   -84,
     -70,   -55,   -46,   -34,   -30,   -23,    23,    24,    25,    26,
      28,    33,    34,    35,    48,    49,    51,    52,    53,    61,
      62,    63,    64,    65,    79,    80,    81,    82,    83,    87,
      88,    89,    90,    91,    96,   105,   106,   107,   108,   109,
     110,   111,   112,   123,   126,   127,   128,   129,   130,   673,
     673,   673,    69,   369,  2236,   -51,  -436,   673,   103,   144,
     145,   146,   147,   148,   673,   122,   176,   537,   673,   673,
     673,   537,   754,   754,   754,   754,   149,   164,   673,   673,
     673,   673,   673,   673,   673,   673,   673,   673,   673,   673,
     673,   673,   673,   673,   673,   673,   673,   673,   673,   673,
     673,   673,   673,   673,   673,   673,   673,   673,   673,    31,
    -436,   -51,   197,   777,   -73,   369,  2236,  -436,  -436,   673,
     673,   673,   673,   673,   673,   -63,   673,   673,   673,   673,
     673,   673,   673,   673,   673,   673,   673,   673,   673,   673,
      84,  -436,  -436,  -436,  -436,  -436,  -436,   529,   165,   166,
    -436,  -436,   151,   168,   169,   171,   173,   184,   189,   195,
     199,   200,   203,   204,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   223,   224,   225,   226,   229,   261,   262,
     263,   264,   265,   268,   277,   282,   283,   288,   289,   290,
     291,   537,   537,   537,   565,   131,   439,   -36,  -436,   795,
     675,   813,   192,   -67,   292,   293,   297,   299,   300,   301,
     302,   334,   335,   338,   339,   353,   355,   358,   366,   367,
     402,   403,   404,   405,   406,   407,   410,   411,   412,   413,
     414,   415,   416,   426,   431,   437,   754,   754,   754,   700,
    2110,   752,  2122,  1479,  2134,  1497,  -436,  -436,   150,   831,
     849,  2146,   867,   885,   903,   921,   939,   957,   975,   993,
    1011,  1029,  1047,  1065,  1083,  1101,  1119,  1137,  1155,  1173,
    1191,  1209,  1227,  1245,  1263,  1281,  1299,  1317,  1335,  1353,
    -436,  -436,  -436,   -31,   -31,  -436,  -436,    31,    31,  -436,
    -436,  -436,  2236,  2236,  2236,  2236,  2236,  2236,   -10,   -10,
    -436,    31,  -436,  -436,   -38,  2091,   187,  -436,   673,  -436,
    -436,  -436,   537,   284,   438,   443,   444,   673,   673,    29,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,  -436,   132,  1515,  2158,   -68,  2247,  -436,  -436,   754,
     754,   754,   754,   754,   754,   754,   754,   754,   754,  -436,
     673,   754,   754,   754,   754,   754,   754,   -18,   754,   754,
     754,  -436,  -436,  -436,   673,  -436,   673,   754,   754,   754,
     754,   754,   754,   754,   754,   754,   754,   754,   754,   754,
     754,   754,   754,   754,   754,   754,   754,   754,   754,   754,
     754,   754,   754,   754,   754,   754,   754,   754,   754,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,    30,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,   673,   673,
     170,   285,  -436,  -436,  -436,  -436,  2170,  1371,  2182,  1389,
    -436,   446,   447,   540,   449,   434,  1533,  1551,  1569,  2194,
    1587,  1605,  1623,  1641,  1659,  1677,  1695,  1713,  1731,  1749,
    1767,  1785,  1803,  1821,  1839,  1857,  1875,  1893,  1911,  1929,
    1947,  1965,  1983,  2001,  2019,  2037,  2055,  -436,  -436,  -436,
    2247,  2247,  2247,  2247,  2247,  2247,   -57,   -57,  -436,   132,
    -436,  2206,  1407,   -20,   -20,  -436,  -436,   132,   132,  -436,
    -436,  -436,  2105,   104,   468,  -436,  2218,  1425,  1443,   452,
     369,  2236,   673,   754,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,    30,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,   754,   754,  -436,  -436,
    -436,  -436,  1461,   560,   453,  2247,   439,  -436,   754,  -436,
    2073,  -436
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  ValueExpressionParser::yydefact_[] =
  {
         0,   155,    24,    91,     0,   156,   157,   146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     2,     4,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
     101,     0,     0,     0,     0,     0,     0,   169,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,   152,   151,    15,   149,   147,     0,     0,     0,
      72,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,   102,   166,    11,     6,     8,     9,   100,    10,   142,
     143,   144,   165,   164,   160,   161,   163,   162,    93,    92,
      95,     7,    94,    96,     0,     0,   168,   167,     0,   148,
     158,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    80,     0,     0,     0,     0,   181,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    22,   131,     0,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   140,
      18,   141,    19,   139,    17,    21,     0,    98,    99,   132,
     130,   105,   106,   107,   128,   129,   103,   104,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     0,     0,
       0,     0,    83,    84,    85,    69,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    81,   178,
     177,   176,   172,   173,   175,   174,    30,    26,    27,    75,
      29,     0,     0,    79,    74,    76,    78,    28,    77,    63,
      64,    65,     0,     0,   180,   179,     0,     0,     0,     0,
      14,   145,     0,     0,    86,    70,    87,    71,   170,   171,
      90,    25,     0,    32,    33,    67,    68,    36,    37,    38,
      59,    60,    34,    35,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    23,   135,     0,     0,    16,   138,
     137,    97,     0,     0,     0,    66,    82,   182,     0,    31,
       0,   183
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  ValueExpressionParser::yypgoto_[] =
  {
      -436,  -436,   307,    73,   -80,  -435,     0,    11,  -197,  -436,
    -436
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  ValueExpressionParser::yydefgoto_[] =
  {
        -1,    62,   125,   366,   206,   484,   126,   121,   207,    66,
     208
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char ValueExpressionParser::yytable_ninf_ = -1;
  const unsigned short int
  ValueExpressionParser::yytable_[] =
  {
        64,   549,   250,   252,   254,   365,   367,   147,    67,   148,
     149,    65,   388,    68,   389,   390,    69,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   292,   147,
      70,   148,   149,   519,   395,   396,   377,   378,   480,   480,
     299,   300,   301,   468,   388,    71,   389,   390,   481,   482,
     365,   367,   129,   130,    72,   131,   132,   133,   134,   120,
     123,   135,   131,   132,   133,   134,    73,   150,   135,   128,
      74,   124,   127,   383,   384,   385,   386,    75,   209,   387,
     211,   213,   144,   145,   146,   539,   540,   541,   258,   259,
     260,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   483,
     483,   362,   364,    76,    77,    78,    79,   604,    80,   158,
     135,   295,   296,    81,    82,    83,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   312,   313,   315,    84,    85,
     205,    86,    87,    88,   212,   249,   251,   253,   255,   316,
     317,    89,    90,    91,    92,    93,   362,   364,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    94,
      95,    96,    97,    98,   159,   597,   318,    99,   100,   101,
     102,   103,   544,   545,   381,   382,   104,   383,   384,   385,
     386,   120,   123,   387,   151,   105,   106,   107,   108,   109,
     110,   111,   112,   124,   127,   369,   370,   371,   372,   373,
     374,   375,   376,   113,   377,   378,   114,   115,   116,   117,
     118,   387,   379,   380,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   152,   153,   154,   155,   156,
     256,   322,   436,   489,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   257,   320,   321,   323,   324,
     149,   325,   552,   326,   361,   363,   369,   370,   371,   372,
     373,   374,   375,   376,   327,   377,   378,   129,   130,   328,
     131,   132,   133,   134,   394,   329,   135,   529,   290,   330,
     331,   533,   534,   332,   333,   537,   538,    63,   543,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   470,   361,
     363,   489,   150,   343,   344,   345,   346,   477,   479,   347,
     258,   259,   260,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   348,   349,   350,   351,   352,   119,   122,   353,   369,
     370,   371,   372,   373,   374,   375,   376,   354,   377,   378,
     532,   157,   355,   356,   204,   472,   210,   553,   357,   358,
     359,   360,   397,   398,   547,   471,   548,   399,   261,   400,
     401,   402,   403,   485,   486,   487,   488,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   404,   405,   293,   294,   406,   407,
     297,   298,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   530,   311,   408,   314,   409,   535,   536,   410,   129,
     130,   542,   131,   132,   133,   134,   411,   412,   135,   551,
     471,   485,   486,   487,   488,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   413,   414,   415,   416,   417,   418,   119,   122,
     419,   420,   421,   422,   423,   424,   425,   606,   369,   370,
     371,   372,   373,   374,   375,   376,   426,   377,   378,   381,
     382,   427,   383,   384,   385,   386,   562,   428,   387,   473,
       1,     2,   160,   161,   474,   475,     3,   558,   559,   560,
     561,   390,   602,   601,   609,   162,     5,     6,     7,     8,
       9,    10,    11,   163,   164,   165,   166,    12,    13,    14,
      15,    16,    17,    18,    19,   167,    20,    21,    22,    23,
     168,    24,    25,   169,    26,    27,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,     0,     0,   129,
     130,     0,   131,   132,   133,   134,   603,   201,   135,     0,
     319,     0,     0,     0,   476,   478,     0,   202,     0,     0,
     261,     0,     0,   203,   369,   370,   371,   372,   373,   374,
     375,   376,     0,   377,   378,   129,   130,     0,   131,   132,
     133,   134,   608,     0,   135,     0,   368,     0,     0,   605,
       0,     0,     0,     0,     0,     0,     1,     2,     0,     0,
       0,   610,     3,     0,     0,     0,     0,   531,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,     0,
       0,   546,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,     0,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,     0,     0,     0,     0,     0,     0,   160,
     161,     0,     0,    59,     0,   129,   130,     0,   131,   132,
     133,   134,   214,    60,   135,   550,   392,     0,     0,    61,
     163,   164,   165,   166,   369,   370,   371,   372,   373,   374,
     375,   376,   167,   377,   378,     0,     0,   168,     0,     0,
     169,   429,     0,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     0,     0,   369,   370,   371,   372,
     373,   374,   375,   376,   246,   377,   378,     0,     0,     0,
       0,     0,     0,   431,   247,     0,     0,     0,     0,     0,
     248,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,     0,     0,     0,     0,   291,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,     0,     0,     0,   391,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,     0,     0,     0,   393,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,     0,
       0,     0,   437,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,     0,     0,     0,     0,
     438,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,     0,     0,     0,     0,   440,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,     0,     0,     0,   441,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,     0,     0,     0,   442,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,     0,
       0,     0,   443,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,     0,     0,     0,     0,
     444,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,     0,     0,     0,     0,   445,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,     0,     0,     0,   446,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,     0,     0,     0,   447,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,     0,
       0,     0,   448,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,     0,     0,     0,     0,
     449,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,     0,     0,     0,     0,   450,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,     0,     0,     0,   451,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,     0,     0,     0,   452,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,     0,
       0,     0,   453,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,     0,     0,     0,     0,
     454,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,     0,     0,     0,     0,   455,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,     0,     0,     0,   456,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,     0,     0,     0,   457,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,     0,
       0,     0,   458,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,     0,     0,     0,     0,
     459,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,     0,     0,     0,     0,   460,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,     0,     0,     0,   461,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,     0,     0,     0,   462,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,     0,
       0,     0,   463,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,     0,     0,     0,     0,
     464,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,     0,     0,     0,     0,   465,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,     0,     0,     0,   466,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,     0,     0,     0,   467,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,     0,
       0,     0,   555,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,     0,     0,     0,     0,
     557,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,     0,     0,     0,     0,   595,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,     0,     0,     0,   599,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,     0,     0,     0,   600,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,     0,
       0,     0,   607,   369,   370,   371,   372,   373,   374,   375,
     376,     0,   377,   378,     0,     0,     0,     0,     0,     0,
     433,   369,   370,   371,   372,   373,   374,   375,   376,     0,
     377,   378,     0,     0,     0,     0,     0,     0,   435,   369,
     370,   371,   372,   373,   374,   375,   376,     0,   377,   378,
       0,     0,     0,     0,     0,     0,   517,   369,   370,   371,
     372,   373,   374,   375,   376,     0,   377,   378,     0,     0,
       0,     0,     0,     0,   563,   369,   370,   371,   372,   373,
     374,   375,   376,     0,   377,   378,     0,     0,     0,     0,
       0,     0,   564,   369,   370,   371,   372,   373,   374,   375,
     376,     0,   377,   378,     0,     0,     0,     0,     0,     0,
     565,   369,   370,   371,   372,   373,   374,   375,   376,     0,
     377,   378,     0,     0,     0,     0,     0,     0,   567,   369,
     370,   371,   372,   373,   374,   375,   376,     0,   377,   378,
       0,     0,     0,     0,     0,     0,   568,   369,   370,   371,
     372,   373,   374,   375,   376,     0,   377,   378,     0,     0,
       0,     0,     0,     0,   569,   369,   370,   371,   372,   373,
     374,   375,   376,     0,   377,   378,     0,     0,     0,     0,
       0,     0,   570,   369,   370,   371,   372,   373,   374,   375,
     376,     0,   377,   378,     0,     0,     0,     0,     0,     0,
     571,   369,   370,   371,   372,   373,   374,   375,   376,     0,
     377,   378,     0,     0,     0,     0,     0,     0,   572,   369,
     370,   371,   372,   373,   374,   375,   376,     0,   377,   378,
       0,     0,     0,     0,     0,     0,   573,   369,   370,   371,
     372,   373,   374,   375,   376,     0,   377,   378,     0,     0,
       0,     0,     0,     0,   574,   369,   370,   371,   372,   373,
     374,   375,   376,     0,   377,   378,     0,     0,     0,     0,
       0,     0,   575,   369,   370,   371,   372,   373,   374,   375,
     376,     0,   377,   378,     0,     0,     0,     0,     0,     0,
     576,   369,   370,   371,   372,   373,   374,   375,   376,     0,
     377,   378,     0,     0,     0,     0,     0,     0,   577,   369,
     370,   371,   372,   373,   374,   375,   376,     0,   377,   378,
       0,     0,     0,     0,     0,     0,   578,   369,   370,   371,
     372,   373,   374,   375,   376,     0,   377,   378,     0,     0,
       0,     0,     0,     0,   579,   369,   370,   371,   372,   373,
     374,   375,   376,     0,   377,   378,     0,     0,     0,     0,
       0,     0,   580,   369,   370,   371,   372,   373,   374,   375,
     376,     0,   377,   378,     0,     0,     0,     0,     0,     0,
     581,   369,   370,   371,   372,   373,   374,   375,   376,     0,
     377,   378,     0,     0,     0,     0,     0,     0,   582,   369,
     370,   371,   372,   373,   374,   375,   376,     0,   377,   378,
       0,     0,     0,     0,     0,     0,   583,   369,   370,   371,
     372,   373,   374,   375,   376,     0,   377,   378,     0,     0,
       0,     0,     0,     0,   584,   369,   370,   371,   372,   373,
     374,   375,   376,     0,   377,   378,     0,     0,     0,     0,
       0,     0,   585,   369,   370,   371,   372,   373,   374,   375,
     376,     0,   377,   378,     0,     0,     0,     0,     0,     0,
     586,   369,   370,   371,   372,   373,   374,   375,   376,     0,
     377,   378,     0,     0,     0,     0,     0,     0,   587,   369,
     370,   371,   372,   373,   374,   375,   376,     0,   377,   378,
       0,     0,     0,     0,     0,     0,   588,   369,   370,   371,
     372,   373,   374,   375,   376,     0,   377,   378,     0,     0,
       0,     0,     0,     0,   589,   369,   370,   371,   372,   373,
     374,   375,   376,     0,   377,   378,     0,     0,     0,     0,
       0,     0,   590,   369,   370,   371,   372,   373,   374,   375,
     376,     0,   377,   378,     0,     0,     0,     0,     0,     0,
     591,   369,   370,   371,   372,   373,   374,   375,   376,     0,
     377,   378,     0,     0,     0,     0,     0,     0,   592,   369,
     370,   371,   372,   373,   374,   375,   376,     0,   377,   378,
       0,     0,     0,     0,     0,     0,   593,   369,   370,   371,
     372,   373,   374,   375,   376,     0,   377,   378,     0,     0,
       0,     0,   469,     0,   611,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   596,     0,     0,   369,
     370,   371,   372,   373,   374,   375,   376,     0,   377,   378,
     381,   382,     0,   383,   384,   385,   386,     0,     0,   387,
       0,   430,   381,   382,     0,   383,   384,   385,   386,     0,
       0,   387,     0,   432,   381,   382,     0,   383,   384,   385,
     386,     0,     0,   387,     0,   434,   129,   130,     0,   131,
     132,   133,   134,     0,     0,   135,     0,   439,   381,   382,
       0,   383,   384,   385,   386,     0,     0,   387,     0,   518,
     129,   130,     0,   131,   132,   133,   134,     0,     0,   135,
       0,   554,   129,   130,     0,   131,   132,   133,   134,     0,
       0,   135,     0,   556,   381,   382,     0,   383,   384,   385,
     386,     0,     0,   387,     0,   566,   129,   130,     0,   131,
     132,   133,   134,     0,     0,   135,     0,   594,   129,   130,
       0,   131,   132,   133,   134,     0,     0,   135,     0,   598,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   369,   370,   371,   372,   373,   374,   375,   376,     0,
     377,   378
  };

  /* YYCHECK.  */
  const short int
  ValueExpressionParser::yycheck_[] =
  {
         0,   436,    82,    83,    84,   202,   203,    80,   100,    82,
      83,     0,    80,   100,    82,    83,   100,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,   101,    80,
     100,    82,    83,   101,   101,   102,    93,    94,     9,     9,
     103,   104,   105,    81,    80,   100,    82,    83,    19,    20,
     247,   248,    90,    91,   100,    93,    94,    95,    96,    59,
      60,    99,    93,    94,    95,    96,   100,    67,    99,     0,
     100,    60,    61,    93,    94,    95,    96,   100,    78,    99,
      80,    81,    92,    93,    94,   103,   104,   105,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    90,
      90,   201,   202,   100,   100,   100,   100,   562,   100,     7,
      99,   131,   132,   100,   100,   100,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   100,   100,
      77,   100,   100,   100,    81,    82,    83,    84,    85,   148,
     149,   100,   100,   100,   100,   100,   246,   247,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,   100,
     100,   100,   100,   100,     8,    81,   102,   100,   100,   100,
     100,   100,   389,   390,    90,    91,   100,    93,    94,    95,
      96,   201,   202,    99,   101,   100,   100,   100,   100,   100,
     100,   100,   100,   202,   203,    84,    85,    86,    87,    88,
      89,    90,    91,   100,    93,    94,   100,   100,   100,   100,
     100,    99,   101,   102,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,   101,   101,   101,   101,   101,
     101,   100,   102,   333,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,   101,   101,   101,   100,   100,
      83,   100,   102,   100,   201,   202,    84,    85,    86,    87,
      88,    89,    90,    91,   100,    93,    94,    90,    91,   100,
      93,    94,    95,    96,   102,   100,    99,   377,   101,   100,
     100,   381,   382,   100,   100,   385,   386,     0,   388,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   318,   246,
     247,   401,   322,   100,   100,   100,   100,   327,   328,   100,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   100,   100,   100,   100,   100,    59,    60,   100,    84,
      85,    86,    87,    88,    89,    90,    91,   100,    93,    94,
     380,    74,   100,   100,    77,   101,    79,   102,   100,   100,
     100,   100,   100,   100,   394,   322,   396,   100,    91,   100,
     100,   100,   100,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   100,   100,   129,   130,   100,   100,
     133,   134,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   145,   100,   147,   100,   383,   384,   100,    90,
      91,   388,    93,    94,    95,    96,   100,   100,    99,   469,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   100,   100,   100,   100,   100,   100,   201,   202,
     100,   100,   100,   100,   100,   100,   100,   597,    84,    85,
      86,    87,    88,    89,    90,    91,   100,    93,    94,    90,
      91,   100,    93,    94,    95,    96,   102,   100,    99,   101,
       3,     4,     5,     6,   101,   101,     9,   101,   101,     9,
     101,    83,   552,   101,   101,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    -1,    90,
      91,    -1,    93,    94,    95,    96,   553,    90,    99,    -1,
     101,    -1,    -1,    -1,   327,   328,    -1,   100,    -1,    -1,
     333,    -1,    -1,   106,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    90,    91,    -1,    93,    94,
      95,    96,   102,    -1,    99,    -1,   101,    -1,    -1,   596,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,   608,     9,    -1,    -1,    -1,    -1,   380,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,   394,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    40,    41,    42,    -1,    44,    45,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,    -1,    -1,    90,    -1,    90,    91,    -1,    93,    94,
      95,    96,    18,   100,    99,   468,   101,    -1,    -1,   106,
      26,    27,    28,    29,    84,    85,    86,    87,    88,    89,
      90,    91,    38,    93,    94,    -1,    -1,    43,    -1,    -1,
      46,   101,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    90,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   100,    -1,    -1,    -1,    -1,    -1,
     106,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    -1,    -1,
      -1,    -1,    81,    -1,   101,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    81,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      90,    91,    -1,    93,    94,    95,    96,    -1,    -1,    99,
      -1,   101,    90,    91,    -1,    93,    94,    95,    96,    -1,
      -1,    99,    -1,   101,    90,    91,    -1,    93,    94,    95,
      96,    -1,    -1,    99,    -1,   101,    90,    91,    -1,    93,
      94,    95,    96,    -1,    -1,    99,    -1,   101,    90,    91,
      -1,    93,    94,    95,    96,    -1,    -1,    99,    -1,   101,
      90,    91,    -1,    93,    94,    95,    96,    -1,    -1,    99,
      -1,   101,    90,    91,    -1,    93,    94,    95,    96,    -1,
      -1,    99,    -1,   101,    90,    91,    -1,    93,    94,    95,
      96,    -1,    -1,    99,    -1,   101,    90,    91,    -1,    93,
      94,    95,    96,    -1,    -1,    99,    -1,   101,    90,    91,
      -1,    93,    94,    95,    96,    -1,    -1,    99,    -1,   101,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  ValueExpressionParser::yystos_[] =
  {
         0,     3,     4,     9,    18,    19,    20,    21,    22,    23,
      24,    25,    30,    31,    32,    33,    34,    35,    36,    37,
      39,    40,    41,    42,    44,    45,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    90,
     100,   106,   108,   109,   113,   114,   116,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   109,
     113,   114,   109,   113,   114,   109,   113,   114,     0,    90,
      91,    93,    94,    95,    96,    99,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    80,    82,    83,
     113,   101,   101,   101,   101,   101,   101,   109,     7,     8,
       5,     6,    18,    26,    27,    28,    29,    38,    43,    46,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    90,   100,   106,   109,   110,   111,   115,   117,   113,
     109,   113,   110,   113,    18,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    90,   100,   106,   110,
     111,   110,   111,   110,   111,   110,   101,   101,   113,   113,
     113,   109,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     101,   101,   101,   109,   109,   113,   113,   109,   109,   103,
     104,   105,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   109,   113,   113,   109,   113,   114,   114,   102,   101,
     101,   101,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   110,   111,   110,   111,   115,   110,   115,   101,    84,
      85,    86,    87,    88,    89,    90,    91,    93,    94,   101,
     102,    90,    91,    93,    94,    95,    96,    99,    80,    82,
      83,   101,   101,   101,   102,   101,   102,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   101,   101,   101,   102,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,    81,    81,
     113,   110,   101,   101,   101,   101,   109,   113,   109,   113,
       9,    19,    20,    90,   112,   110,   110,   110,   110,   111,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   101,   101,   101,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   111,
     110,   109,   113,   111,   111,   110,   110,   111,   111,   103,
     104,   105,   110,   111,   115,   115,   109,   113,   113,   112,
     109,   113,   102,   102,   101,   101,   101,   101,   101,   101,
       9,   101,   102,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,    81,    81,   101,   101,
     101,   101,   113,   110,   112,   110,   111,   101,   102,   101,
     110,   101
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  ValueExpressionParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
      63,    58,   335,   336,   337,   338,    60,    62,   339,   340,
      45,    43,    37,    42,    47,    38,    94,   341,   342,    46,
      40,    41,    44,   120,   121,   122,    33
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  ValueExpressionParser::yyr1_[] =
  {
         0,   107,   108,   108,   108,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   112,
     112,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   116,   117
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ValueExpressionParser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     2,     3,     5,     3,     6,     4,     4,     4,
       4,     4,     4,     6,     1,     4,     3,     3,     3,     3,
       3,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     2,     3,     3,     3,     3,     5,     4,     4,     3,
       4,     4,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     3,     5,     3,     3,     3,     4,     4,     1,     1,
       2,     1,     3,     3,     3,     3,     3,     6,     4,     4,
       3,     2,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     6,     6,     4,
       4,     4,     3,     3,     3,     5,     1,     3,     4,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       4,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     8,     8
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const ValueExpressionParser::yytname_[] =
  {
    "$end", "error", "$undefined", "\"scalarID\"", "\"vectorID\"",
  "\"faceScalarID\"", "\"faceVectorID\"", "\"cellSetID\"",
  "\"cellZoneID\"", "\"number\"", "\"vector\"", "\"sexpression\"",
  "\"expression\"", "\"lexpression\"", "\"flexpression\"",
  "\"vexpression\"", "\"fsexpression\"", "\"fvexpression\"",
  "TOKEN_VECTOR", "TOKEN_TRUE", "TOKEN_FALSE", "TOKEN_pi", "TOKEN_rand",
  "TOKEN_id", "TOKEN_randNormal", "TOKEN_position", "TOKEN_fposition",
  "TOKEN_fprojection", "TOKEN_face", "TOKEN_area", "TOKEN_volume",
  "TOKEN_dist", "TOKEN_rdist", "TOKEN_set", "TOKEN_zone", "TOKEN_div",
  "TOKEN_grad", "TOKEN_curl", "TOKEN_snGrad", "TOKEN_magSqrGradGrad",
  "TOKEN_laplacian", "TOKEN_integrate", "TOKEN_sum", "TOKEN_interpolate",
  "TOKEN_average", "TOKEN_reconstruct", "TOKEN_surf", "TOKEN_deltaT",
  "TOKEN_time", "TOKEN_pow", "TOKEN_log", "TOKEN_exp", "TOKEN_mag",
  "TOKEN_sin", "TOKEN_cos", "TOKEN_tan", "TOKEN_min", "TOKEN_max",
  "TOKEN_sqr", "TOKEN_sqrt", "TOKEN_log10", "TOKEN_asin", "TOKEN_acos",
  "TOKEN_atan", "TOKEN_sinh", "TOKEN_cosh", "TOKEN_tanh", "TOKEN_asinh",
  "TOKEN_acosh", "TOKEN_atanh", "TOKEN_erf", "TOKEN_erfc", "TOKEN_lgamma",
  "TOKEN_besselJ0", "TOKEN_besselJ1", "TOKEN_besselY0", "TOKEN_besselY1",
  "TOKEN_sign", "TOKEN_pos", "TOKEN_neg", "'?'", "':'", "TOKEN_OR",
  "TOKEN_AND", "TOKEN_NEQ", "TOKEN_EQ", "'<'", "'>'", "TOKEN_GEQ",
  "TOKEN_LEQ", "'-'", "'+'", "'%'", "'*'", "'/'", "'&'", "'^'",
  "TOKEN_NOT", "TOKEN_NEG", "'.'", "'('", "')'", "','", "'x'", "'y'",
  "'z'", "'!'", "$accept", "unit", "vexp", "fsexp", "fvexp", "scalar",
  "exp", "lexp", "flexp", "vector", "fvector", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const ValueExpressionParser::rhs_number_type
  ValueExpressionParser::yyrhs_[] =
  {
       108,     0,    -1,   113,    -1,   109,    -1,   114,    -1,   116,
      -1,   109,    91,   109,    -1,   113,    93,   109,    -1,   109,
      93,   113,    -1,   109,    94,   113,    -1,   109,    96,   109,
      -1,   109,    90,   109,    -1,    90,   109,    -1,   100,   109,
     101,    -1,   114,    80,   109,    81,   109,    -1,    25,   100,
     101,    -1,    40,   100,   110,   102,   109,   101,    -1,    44,
     100,   111,   101,    -1,    41,   100,   111,   101,    -1,    42,
     100,   111,   101,    -1,    36,   100,   113,   101,    -1,    45,
     100,   110,   101,    -1,    37,   100,   109,   101,    -1,    35,
     100,   110,   102,   109,   101,    -1,     4,    -1,    46,   100,
     112,   101,    -1,   110,    91,   110,    -1,   110,    93,   110,
      -1,   111,    95,   111,    -1,   110,    94,   110,    -1,   110,
      90,   110,    -1,    49,   100,   110,   102,   112,   101,    -1,
      50,   100,   110,   101,    -1,    51,   100,   110,   101,    -1,
      58,   100,   110,   101,    -1,    59,   100,   110,   101,    -1,
      53,   100,   110,   101,    -1,    54,   100,   110,   101,    -1,
      55,   100,   110,   101,    -1,    60,   100,   110,   101,    -1,
      61,   100,   110,   101,    -1,    62,   100,   110,   101,    -1,
      63,   100,   110,   101,    -1,    64,   100,   110,   101,    -1,
      65,   100,   110,   101,    -1,    66,   100,   110,   101,    -1,
      67,   100,   110,   101,    -1,    68,   100,   110,   101,    -1,
      69,   100,   110,   101,    -1,    70,   100,   110,   101,    -1,
      71,   100,   110,   101,    -1,    72,   100,   110,   101,    -1,
      73,   100,   110,   101,    -1,    74,   100,   110,   101,    -1,
      75,   100,   110,   101,    -1,    76,   100,   110,   101,    -1,
      77,   100,   110,   101,    -1,    78,   100,   110,   101,    -1,
      79,   100,   110,   101,    -1,    56,   100,   110,   101,    -1,
      57,   100,   110,   101,    -1,    90,   110,    -1,   100,   110,
     101,    -1,   111,    99,   103,    -1,   111,    99,   104,    -1,
     111,    99,   105,    -1,   115,    80,   110,    81,   110,    -1,
      52,   100,   110,   101,    -1,    52,   100,   111,   101,    -1,
      29,   100,   101,    -1,    38,   100,   113,   101,    -1,    43,
     100,   113,   101,    -1,     5,    -1,   117,    -1,   111,    91,
     111,    -1,   110,    93,   111,    -1,   111,    93,   110,    -1,
     111,    96,   111,    -1,   111,    94,   110,    -1,   111,    90,
     111,    -1,    90,   111,    -1,   100,   111,   101,    -1,   115,
      80,   111,    81,   111,    -1,    26,   100,   101,    -1,    27,
     100,   101,    -1,    28,   100,   101,    -1,    38,   100,   109,
     101,    -1,    43,   100,   109,   101,    -1,     6,    -1,     9,
      -1,    90,     9,    -1,     9,    -1,   113,    91,   113,    -1,
     113,    90,   113,    -1,   113,    93,   113,    -1,   113,    92,
     113,    -1,   113,    94,   113,    -1,    49,   100,   113,   102,
     112,   101,    -1,    50,   100,   113,   101,    -1,    51,   100,
     113,   101,    -1,   109,    95,   109,    -1,    90,   113,    -1,
     100,   113,   101,    -1,    58,   100,   113,   101,    -1,    59,
     100,   113,   101,    -1,    53,   100,   113,   101,    -1,    54,
     100,   113,   101,    -1,    55,   100,   113,   101,    -1,    60,
     100,   113,   101,    -1,    61,   100,   113,   101,    -1,    62,
     100,   113,   101,    -1,    63,   100,   113,   101,    -1,    64,
     100,   113,   101,    -1,    65,   100,   113,   101,    -1,    66,
     100,   113,   101,    -1,    67,   100,   113,   101,    -1,    68,
     100,   113,   101,    -1,    69,   100,   113,   101,    -1,    70,
     100,   113,   101,    -1,    71,   100,   113,   101,    -1,    72,
     100,   113,   101,    -1,    73,   100,   113,   101,    -1,    74,
     100,   113,   101,    -1,    75,   100,   113,   101,    -1,    76,
     100,   113,   101,    -1,    77,   100,   113,   101,    -1,    78,
     100,   113,   101,    -1,    79,   100,   113,   101,    -1,    56,
     100,   113,   101,    -1,    57,   100,   113,   101,    -1,    52,
     100,   113,   101,    -1,    39,   100,   113,   101,    -1,    52,
     100,   109,   101,    -1,    35,   100,   109,   101,    -1,    35,
     100,   110,   101,    -1,    35,   100,   110,   102,   113,   101,
      -1,    40,   100,   113,   101,    -1,    40,   100,   113,   102,
     113,   101,    -1,    40,   100,   110,   102,   113,   101,    -1,
      44,   100,   110,   101,    -1,    41,   100,   110,   101,    -1,
      42,   100,   110,   101,    -1,   109,    99,   103,    -1,   109,
      99,   104,    -1,   109,    99,   105,    -1,   114,    80,   113,
      81,   113,    -1,    21,    -1,    31,   100,   101,    -1,    32,
     100,   109,   101,    -1,    30,   100,   101,    -1,    22,   100,
     101,    -1,    24,   100,   101,    -1,    23,   100,   101,    -1,
      47,   100,   101,    -1,    48,   100,   101,    -1,     3,    -1,
      19,    -1,    20,    -1,    33,   100,     7,   101,    -1,    34,
     100,     8,   101,    -1,   113,    86,   113,    -1,   113,    87,
     113,    -1,   113,    89,   113,    -1,   113,    88,   113,    -1,
     113,    85,   113,    -1,   113,    84,   113,    -1,   100,   114,
     101,    -1,   114,    83,   114,    -1,   114,    82,   114,    -1,
     106,   114,    -1,    46,   100,    19,   101,    -1,    46,   100,
      20,   101,    -1,   110,    86,   110,    -1,   110,    87,   110,
      -1,   110,    89,   110,    -1,   110,    88,   110,    -1,   110,
      85,   110,    -1,   110,    84,   110,    -1,   100,   115,   101,
      -1,   115,    83,   115,    -1,   115,    82,   115,    -1,   106,
     115,    -1,    18,   100,   113,   102,   113,   102,   113,   101,
      -1,    18,   100,   110,   102,   110,   102,   110,   101,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  ValueExpressionParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    11,    15,    19,    23,
      27,    31,    35,    38,    42,    48,    52,    59,    64,    69,
      74,    79,    84,    89,    96,    98,   103,   107,   111,   115,
     119,   123,   130,   135,   140,   145,   150,   155,   160,   165,
     170,   175,   180,   185,   190,   195,   200,   205,   210,   215,
     220,   225,   230,   235,   240,   245,   250,   255,   260,   265,
     270,   275,   278,   282,   286,   290,   294,   300,   305,   310,
     314,   319,   324,   326,   328,   332,   336,   340,   344,   348,
     352,   355,   359,   365,   369,   373,   377,   382,   387,   389,
     391,   394,   396,   400,   404,   408,   412,   416,   423,   428,
     433,   437,   440,   444,   449,   454,   459,   464,   469,   474,
     479,   484,   489,   494,   499,   504,   509,   514,   519,   524,
     529,   534,   539,   544,   549,   554,   559,   564,   569,   574,
     579,   584,   589,   594,   599,   604,   611,   616,   623,   630,
     635,   640,   645,   649,   653,   657,   663,   665,   669,   674,
     678,   682,   686,   690,   694,   698,   700,   702,   704,   709,
     714,   718,   722,   726,   730,   734,   738,   742,   746,   750,
     753,   758,   763,   767,   771,   775,   779,   783,   787,   791,
     795,   799,   802,   811
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ValueExpressionParser::yyrline_[] =
  {
         0,   178,   178,   179,   180,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   273,
     274,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   374,   377
  };

  // Print the state stack on the debug stream.
  void
  ValueExpressionParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  ValueExpressionParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "), ";
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  ValueExpressionParser::token_number_type
  ValueExpressionParser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   106,     2,     2,     2,    92,    95,     2,
     100,   101,    93,    91,   102,    90,    99,    94,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,     2,
      86,     2,    87,    80,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    96,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     103,   104,   105,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    82,    83,    84,    85,    88,
      89,    97,    98
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int ValueExpressionParser::yyeof_ = 0;
  const int ValueExpressionParser::yylast_ = 2341;
  const int ValueExpressionParser::yynnts_ = 11;
  const int ValueExpressionParser::yyempty_ = -2;
  const int ValueExpressionParser::yyfinal_ = 128;
  const int ValueExpressionParser::yyterror_ = 1;
  const int ValueExpressionParser::yyerrcode_ = 256;
  const int ValueExpressionParser::yyntokens_ = 107;

  const unsigned int ValueExpressionParser::yyuser_token_number_max_ = 342;
  const ValueExpressionParser::token_number_type ValueExpressionParser::yyundef_token_ = 2;

} // namespace ve

#line 380 "ValueExpressionParser.yy"


void ve::ValueExpressionParser::error (const ve::ValueExpressionParser::location_type& l,const std::string& m)
{
     driver.error (l, m);
}

