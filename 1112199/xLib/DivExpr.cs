using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace xLib
{
    public class DivExpr : BinaryExpr
    {
        public DivExpr(Expression e1, Expression e2)
            : base(e1, e2)
        {
        }

        public override double evaluate(double x)
        {
            return expr1.evaluate(x) / expr2.evaluate(x);
        }

        public override Expression derive()
        {
            return new AddExpr(
                new DivExpr(new MulExpr(expr1.derive(), expr2), new MulExpr(expr2, expr2)),
                new MulExpr(new MonomialExpr(-1, 0), new DivExpr(new MulExpr(expr1, expr2.derive()), new MulExpr(expr2, expr2)))
                );
        }

        public override string toString(Notation ntn)
        {
            return expr1.toString(ntn) + " / " + expr2.toString(ntn);
        }
    }
}
