using System;
using System.Collections.Generic;
using System.Text;

namespace TestLib
{
    public class Main
    {
        static List<TestClass> lst;
        static int idx = 0;
        static int idx2 = 0;

        public static void TestGC()
        {
            lst = new List<TestClass>();

            System.Threading.Thread th = new System.Threading.Thread(MainLoop);
            th.Start();

            while (true)
            {
                System.Threading.Thread.Sleep(1000);
                Console.WriteLine($"lst[0]={lst[0]}");
            }
        }

        static void MainLoop()
        {
            while (true)
            {
                TestClass obj = new TestClass();
                obj.Byte = 1;
                obj.Int = idx;
                obj.Object = new TestClass2();
                obj.Object.Long = idx + 1;
                var s = new TestStruct();
                s.Object = new TestClass2();
                s.Object.Long = idx + 2;
                obj.Object.Struct = s;
                lst = new List<TestClass>();
                lst.Add(obj);

                if (lst.Count > 5)
                    lst.RemoveRange(2, 3);
                System.Threading.Thread.Sleep(10);
                idx += 10;
                idx2++;
            }
        }
    }
}
