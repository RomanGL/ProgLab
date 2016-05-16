namespace XmlParser
{
    public sealed class PathsData
    {
        public PathsData(string delimiter, string paths)
        {
            Delimiter = delimiter;
            Paths = paths;
        }

        public string Delimiter { get; private set; }

        public string Paths { get; private set; }        
    }
}
