using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace XmlParser
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                Console.WriteLine("XmlParser error: missing argument (file path).");
                return;
            }

            IParser xmlParser = new XmlParser();
            if (xmlParser.Parse(args[0]))
            {
                Console.WriteLine($"\n{xmlParser.Result.Delimiter}");
                Console.WriteLine(xmlParser.Result.Paths);
            }
        }
    }
}
