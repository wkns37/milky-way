using System;
using System.Collections.Generic;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;

namespace Converter
{
    internal class App
    {
        static void Main(string[] args)
        {
            // Book name
            Console.Write("Enter book name: ");
            string name = Console.ReadLine().Trim();
            if (!CheckInput(name, "book name"))
                return;

            // Author
            Console.Write("Enter author: ");
            string author = Console.ReadLine().Trim();
            if (!CheckInput(author, "author"))
                return;

            // ISBN
            Console.Write("Enter ISBN: ");
            string ISBN = Console.ReadLine().Trim();
            if (!CheckInput(ISBN, "ISBN"))
                return;

            // Do hashing
            string bookFile = Hash(name);
            string coverFile = Hash("[COVER] " + name);

            // Build JSON
            Dictionary<string, string> json = new Dictionary<string, string>
            {
                { "File", bookFile },
                { "Cover", coverFile },
                { "Name", name },
                { "Author", author },
                { "ISBN", ISBN }
            };

            // Print JSON
            Console.WriteLine(JsonSerializer.Serialize(json, new JsonSerializerOptions
            {
                WriteIndented = true
            }));
            Console.Write("Press ENTER to exit...");
            Console.ReadLine();
        }

        private static bool CheckInput(string input, string value)
        {
            if (string.IsNullOrEmpty(input))
            {
                Console.WriteLine("Invalid " + value + " value");
                Console.Write("Press ENTER to exit...");
                Console.ReadLine();
                return false;
            }

            return true;
        }
        private static string Hash(string input)
        {
            using SHA1Managed sha1 = new SHA1Managed();
            byte[] hash = sha1.ComputeHash(Encoding.UTF8.GetBytes(input));
            StringBuilder builder = new StringBuilder(hash.Length * 2);

            foreach (byte b in hash)
            {
                builder.Append(b.ToString("x2"));
            }

            return builder.ToString().Substring(0, 15);
        }
    }
}
