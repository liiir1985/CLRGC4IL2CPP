using System;
using System.Collections.Generic;
using System.Text;

namespace TestLib
{
    public class Main
    {
        static List<TestClass> lst;
        
        public static void TestGC()
        {
            lst = new List<TestClass>();

            System.Threading.Thread th = new System.Threading.Thread(MainLoop);
            th.Start();

            while (true)
            {
                System.Threading.Thread.Sleep(100);
            }
        }

        static void MainLoop()
        {
            while (true)
            {
                TestClass obj = new TestClass();
                obj.Byte = 1;
                obj.Int = 2;
                obj.Object = new TestClass2();
                var s = new TestStruct();
                s.Object = new TestClass2();
                obj.Object.Struct = s;
                lst = new List<TestClass>();
                lst.Add(obj);

                if (lst.Count > 50000)
                    lst.RemoveRange(10000, 40000);
                System.Threading.Thread.Sleep(100);
            }
        }
    }
}
