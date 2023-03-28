using Microsoft.Win32;
using MyBooks.Commands;
using MyBooks.Commands.Base;
using MyBooks.Models;
using MyBooks.Services;
using MyBooks.ViewModels.Base;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Windows;

namespace MyBooks.ViewModels
{
    internal class MainWindowViewModel : ViewModel
    {
        #region BookShelves : List<BookShelf>

        private List<BookShelf> bookShelves;
        public List<BookShelf> BookShelves { get => bookShelves; private set => Set(ref bookShelves, value); }

        #endregion

        #region SelectedBookShelf : BookShelf

        private BookShelf selectedBookShelf;
        public BookShelf SelectedBookShelf { get => selectedBookShelf; set => Set(ref selectedBookShelf, value); }

        #endregion

        #region SelectedBook : Book

        private Book selectedBook;
        public Book SelectedBook { get => selectedBook; set => Set(ref selectedBook, value); }

        #endregion

        #region Status : string

        public string status;
        public string Status { get => status; private set => Set(ref status, value); }

        #endregion

        #region UpdateCommand : Command

        public Command UpdateCommand { get; }

        private void UpdateCommandExecute(object parameter)
        {
            UpdateData();
        }

        #endregion

        #region ReadBookCommand : Command

        public Command ReadBookCommand { get; }

        private bool CanReadBookCommandExecute(object parameter)
        {
            if (parameter is string file)
            {
                return File.Exists(file) && File.Exists(Properties.Settings.Default.AcrobatPath);
            }

            return false;
        }

        private void ReadBookCommandExecute(object parameter)
        {
            if (parameter is string file)
            {
                try
                {
                    Process process = new Process
                    {
                        StartInfo = new ProcessStartInfo
                        {
                            FileName = Properties.Settings.Default.AcrobatPath,
                            Arguments = file
                        }
                    };

                    process.Start();
                }
                catch (Exception e)
                {
                    Status = e.Message;
                }
            }
        }

        #endregion

        #region ChooseReaderPath : Command

        public Command ChooseReaderPath { get; }

        private void ChooseReaderPathExecute(object parameter)
        {
            OpenFileDialog dialog = new OpenFileDialog
            {
                Filter = "Acrobat Reader|AcroRd32.exe"
            };

            if (dialog.ShowDialog() == true)
            {
                Properties.Settings.Default.AcrobatPath = dialog.FileName;
                Properties.Settings.Default.Save();
            }
        }

        #endregion

        #region CloseApplicationCommand : Command

        public Command CloseApplicationCommand { get; }

        private void CloseApplicationCommandExecute(object parameter)
        {
            Application.Current.Shutdown();
        }

        #endregion

        public MainWindowViewModel()
        {
            CloseApplicationCommand = new LambdaCommand(CloseApplicationCommandExecute);
            UpdateCommand = new LambdaCommand(UpdateCommandExecute);
            ReadBookCommand = new LambdaCommand(ReadBookCommandExecute, CanReadBookCommandExecute);
            ChooseReaderPath = new LambdaCommand(ChooseReaderPathExecute);

            UpdateData();
        }

        private void UpdateData()
        {
            BookShelves = Database.GetData();

            if (BookShelves != null)
            {
                Status = $"Updated: {DateTime.Now:dd/MM/yyyy HH:mm}";
            }
            else
            {
                Status = "Error reading metadata file";
            }
        }
    }
}
