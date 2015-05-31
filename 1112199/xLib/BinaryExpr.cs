using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace xLib
{
    public abstract class BinaryExpr : Expression
    {
        protected Expression expr1;
        protected Expression expr2;

        public BinaryExpr(Expression ex1, Expression ex2)
        {
            expr1 = ex1;
            expr2 = ex2;
        }
        public abstract override double evaluate(double x);

        public abstract override Expression derive();

        public abstract override string toString(Notation ntn);
    }
}
