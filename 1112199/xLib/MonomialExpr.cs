using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace xLib
{
    public class MonomialExpr : Expression
    {
        private double a;
        private double n;

        public static Expression createObject(double val_a, double val_n)
        {
            if (val_a == 0 || val_n == 0)
                return ConstExpr.createObject(val_a);
            return new MonomialExpr(val_a, val_n);
        }

        public MonomialExpr(double val_a, double val_n)
        {
            a = val_a;
            n = val_n;
        }

        public override double evaluate(double x)
        {
            return a * Math.Pow(x, n);
        }

        public override Expression derive()
        {
            return new MonomialExpr(a * n, n - 1);
        }

        public override string toString(Notation ntn)
        {
            return a.ToString() + "xX^" + n.ToString();
        }
    }
}
