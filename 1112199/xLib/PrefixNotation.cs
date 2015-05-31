using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace xLib
{
    public class PrefixNotation : Notation
    {
        public override string arrange(string op, string opr1, string opr2)
        {
            return op + opr2 + opr1;
        }
    }
}
