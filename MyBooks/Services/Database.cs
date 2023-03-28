using MyBooks.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;

namespace MyBooks.Services
{
    internal class Database
    {
        private static readonly string metadataFile = "metadata.json";

        public static List<BookShelf> GetData()
        {
            List<BookShelf> bookShelves = null;
            try
            {
                string data = File.ReadAllText(metadataFile);
                bookShelves = JsonSerializer.Deserialize<List<BookShelf>>(data);
            }
            catch (Exception) { }

            return bookShelves;
        }
    }
}
