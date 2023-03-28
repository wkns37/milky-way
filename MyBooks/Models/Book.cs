using System.IO;

namespace MyBooks.Models
{
    internal class Book
    {
        private string _file;
        public string File { get => _file; set => _file = Path.GetFullPath(value); }

        private string _cover;
        public string Cover { get => _cover; set => _cover = Path.GetFullPath(value); }

        public string Title { get; set; }

        public string Author { get; set; }

        public string ISBN { get; set; }
    }
}
