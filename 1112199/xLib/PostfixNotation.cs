using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace xLib
{
    public class PostfixNotation : Notation
    {
        public override string arrange(string op, string opr1, string opr2)
        {
            return opr1 + opr2 + op;
        }
    }
}
