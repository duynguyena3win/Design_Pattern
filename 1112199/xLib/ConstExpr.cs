using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace xLib
{
    public class ConstExpr : Expression
    {
        private double value;
        private static ConstExpr ZERO;
        public ConstExpr(double val)
        {
            value = val;
        }

        public static ConstExpr getZero()
        {
            if (ZERO == null)
                ZERO = new ConstExpr(0);
            return ZERO;
        }

        public static Expression createObject(double val)
        {
            if (val == 0)
                return getZero();
            return new ConstExpr(val);
        }

        public override Expression derive()
        {
            return new ConstExpr(0);
        }

        public override double evaluate(double x)
        {
            return value;
        }

        public override string toString(Notation ntn)
        {
            return value.ToString();
        }
    }
}
