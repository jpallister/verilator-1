// -*- C++ -*-
//*************************************************************************
// DESCRIPTION: Verilator: Propagate constants across AST
//
// Code available from: http://www.veripool.org/verilator
//
// AUTHORS: Wilson Snyder with Paul Wasson, Duane Gabli
//
//*************************************************************************
//
// Copyright 2003-2009 by Wilson Snyder.  This program is free software; you can
// redistribute it and/or modify it under the terms of either the GNU
// Lesser General Public License Version 3 or the Perl Artistic License
// Version 2.0.
//
// Verilator is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
//*************************************************************************

#ifndef _V3CONST_H_
#define _V3CONST_H_ 1
#include "config_build.h"
#include "verilatedos.h"
#include "V3Error.h"
#include "V3Ast.h"

//============================================================================

class V3Const {
public:
    // Force this cell node's parameter list to become a constant
    // Return new node that may have replaced nodep
    static AstNode* constifyParamsEdit(AstNode* nodep);
    // Everything that's possible
    static void constifyAll(AstNetlist* nodep);
    // Also, warn
    static void constifyAllLint(AstNetlist* nodep);
    // C++ datatypes
    static void constifyCpp(AstNetlist* nodep);
    // Only the current node and lower
    // Return new node that may have replaced nodep
    static AstNode* constifyEdit(AstNode* nodep);
    // Only the current node and lower, with special SenTree optimization
    // Return new node that may have replaced nodep
    static AstNode* constifyExpensiveEdit(AstNode* nodep);
};

#endif // Guard
