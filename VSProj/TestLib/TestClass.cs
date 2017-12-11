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

        public override string ToString()
        {
            return $"TestClass:{Int}, Object={Object}";
        }
    }

    class TestClass2
    {
        public long Long { get; set; }
        public TestStruct Struct { get; set; }
        public override string ToString()
        {
            return $"TestClass2:{Long}, Struct={Struct}";
        }
    }

    struct TestStruct
    {
        public byte Byte { get; set; }
        public int Int { get; set; }
        public TestClass2 Object { get; set; }
        public override string ToString()
        {
            return $"TestClass:{Int}, Object={Object}";
        }
    }
}
