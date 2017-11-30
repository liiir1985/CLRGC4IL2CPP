using System;
using System.Collections.Generic;
using System.Text;

namespace TestLib
{
    class TestClass
    {
        public byte Byte { get; set; }
        public int Int { get; set; }
        public TestClass2 Object { get; set; }
    }

    class TestClass2
    {
        public long Long { get; set; }
        public TestStruct Struct { get; set; }
    }

    struct TestStruct
    {
        public byte Byte { get; set; }
        public int Int { get; set; }
        public TestClass2 Object { get; set; }
    }
}
