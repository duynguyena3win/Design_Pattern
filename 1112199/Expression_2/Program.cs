using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using xLib;
namespace Expression_2
{
    class Program
    {
        static void Main(string[] args)
        {
            DivExpr add = new DivExpr(new MonomialExpr(5, 2), new MonomialExpr(4, 3));
            //Console.WriteLine(add.derive().toString());
        }
    }
}
