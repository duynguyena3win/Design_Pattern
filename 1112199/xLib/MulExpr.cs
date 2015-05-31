using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace xLib
{
    public class MulExpr : BinaryExpr
    {
        public MulExpr(Expression ex1, Expression ex2)
            :base(ex1, ex2)
        {
            
        }

        public override double evaluate(double x)
        {
            return expr1.evaluate(x) * expr2.evaluate(x);
        }

        public override Expression derive()
        {
            return new AddExpr(new MulExpr(expr1.derive(), expr2), new MulExpr(expr2.derive(), expr1));
        }

        public override string toString(Notation ntn)
        {
            return expr1.toString(ntn) + " x " + expr2.toString(ntn);
        }
    }
}
