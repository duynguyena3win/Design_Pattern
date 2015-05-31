using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace xLib
{
    public abstract class Expression
    {
        public abstract double evaluate(double x);
        public abstract Expression derive();
        public abstract string toString(Notation ntn);
    }
}
