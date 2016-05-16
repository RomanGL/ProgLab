using System;
using System.Linq;
using System.Xml.Linq;

namespace XmlParser
{
    public sealed class XmlParser : IParser
    {
        public PathsData Result { get; private set; }

        public bool Parse(string filePath)
        {
            XElement root = null;
            try
            {
                root = XElement.Load(filePath);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"XmlParser error: {ex.Message}");
                return false;
            }

            Console.Error.WriteLine("XmlParser info: XML file is valid.");

            XElement delim = FindElement(root, "delim");
            XElement paths = FindElement(root, "paths");

            bool error = false;

            if (delim == null)
            {
                error = true;
                Console.WriteLine("XmlParser error: can't find <delim> tag.");
            }

            if (paths == null)
            {
                error = true;
                Console.WriteLine("XmlParser error: can't find <paths> tag.");
            }

            if (String.IsNullOrEmpty(delim.Value))
            {
                error = true;
                Console.Write("XmlParser error: <delim> is empty.");
            }

            if (String.IsNullOrWhiteSpace(paths.Value))
            {
                error = true;
                Console.Write("XmlParser error: <paths> is empty.");
            }

            if (!error)
                Result = new PathsData(delim.Value, paths.Value);

            return !error;
        }

        private static XElement FindElement(XElement root, string name)
        {
            return root.Descendants(XName.Get(name)).FirstOrDefault();
        }
    }
}
