using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace xLib
{
    public class AddExpr : BinaryExpr
    {
        public AddExpr(Expression ex1, Expression ex2)
            : base(ex1, ex2)
        {
            
        }

        public override double evaluate(double x)
        {
            return base.expr1.evaluate(x) + base.expr2.evaluate(x);
        }

        public override Expression derive()
        {
            return new AddExpr(base.expr1.derive(), base.expr2.derive());
        }

        public override string toString(Notation ntn)
        {
            //return ntn;
            return expr1.toString(ntn) + " + " + expr2.toString(ntn);
        }
    }
}
