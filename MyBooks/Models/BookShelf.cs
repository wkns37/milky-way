using System.Collections.Generic;

namespace MyBooks.Models
{
    internal class BookShelf
    {
        public string Header { get; set; }

        public List<Book> Books { get; set; }
    }
}
