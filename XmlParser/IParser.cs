namespace XmlParser
{
    public interface IParser
    {
        bool Parse(string filePath);

        PathsData Result { get; }
    }
}
