#pragma once
#include "Program.h"

namespace Gabinet {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;
    /// <summary>
    /// Summary for Logowanie
    /// </summary>
    public ref class Logowanie : public System::Windows::Forms::Form
    {
    public:
        Logowanie(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }
    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Logowanie()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^  logowanieZaloguj;
    private: System::Windows::Forms::Button^  logowanieAnuluj;
    private: System::Windows::Forms::TextBox^  txtuzytkownik;
    private: System::Windows::Forms::TextBox^  txthaslo;
    private: System::Windows::Forms::PictureBox^  zdjUzytkownik;
    private: System::Windows::Forms::PictureBox^  zdjHaslo;
    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Logowanie::typeid));
            this->logowanieZaloguj = (gcnew System::Windows::Forms::Button());
            this->logowanieAnuluj = (gcnew System::Windows::Forms::Button());
            this->txtuzytkownik = (gcnew System::Windows::Forms::TextBox());
            this->txthaslo = (gcnew System::Windows::Forms::TextBox());
            this->zdjUzytkownik = (gcnew System::Windows::Forms::PictureBox());
            this->zdjHaslo = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zdjUzytkownik))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zdjHaslo))->BeginInit();
            this->SuspendLayout();
            // 
            // logowanieZaloguj
            // 
            this->logowanieZaloguj->BackColor = System::Drawing::Color::DodgerBlue;
            this->logowanieZaloguj->Cursor = System::Windows::Forms::Cursors::Hand;
            this->logowanieZaloguj->FlatAppearance->BorderSize = 0;
            this->logowanieZaloguj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->logowanieZaloguj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->logowanieZaloguj->ForeColor = System::Drawing::Color::White;
            this->logowanieZaloguj->Location = System::Drawing::Point(128, 147);
            this->logowanieZaloguj->Name = L"logowanieZaloguj";
            this->logowanieZaloguj->Size = System::Drawing::Size(142, 32);
            this->logowanieZaloguj->TabIndex = 0;
            this->logowanieZaloguj->Text = L"Zaloguj";
            this->logowanieZaloguj->UseVisualStyleBackColor = false;
            this->logowanieZaloguj->Click += gcnew System::EventHandler(this, &Logowanie::logowanieZaloguj_Click);
            // 
            // logowanieAnuluj
            // 
            this->logowanieAnuluj->BackColor = System::Drawing::Color::DodgerBlue;
            this->logowanieAnuluj->Cursor = System::Windows::Forms::Cursors::Hand;
            this->logowanieAnuluj->FlatAppearance->BorderSize = 0;
            this->logowanieAnuluj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->logowanieAnuluj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->logowanieAnuluj->ForeColor = System::Drawing::Color::White;
            this->logowanieAnuluj->Location = System::Drawing::Point(30, 146);
            this->logowanieAnuluj->Name = L"logowanieAnuluj";
            this->logowanieAnuluj->Size = System::Drawing::Size(92, 33);
            this->logowanieAnuluj->TabIndex = 1;
            this->logowanieAnuluj->Text = L"Anuluj";
            this->logowanieAnuluj->UseVisualStyleBackColor = false;
            this->logowanieAnuluj->Click += gcnew System::EventHandler(this, &Logowanie::logowanieAnuluj_Click);
            // 
            // txtuzytkownik
            // 
            this->txtuzytkownik->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->txtuzytkownik->Location = System::Drawing::Point(74, 41);
            this->txtuzytkownik->Name = L"txtuzytkownik";
            this->txtuzytkownik->Size = System::Drawing::Size(196, 29);
            this->txtuzytkownik->TabIndex = 4;
            this->txtuzytkownik->Text = L"U¿ytkownik";
            this->txtuzytkownik->Click += gcnew System::EventHandler(this, &Logowanie::txtuzytkownik_Click);
            // 
            // txthaslo
            // 
            this->txthaslo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->txthaslo->Location = System::Drawing::Point(74, 89);
            this->txthaslo->Name = L"txthaslo";
            this->txthaslo->Size = System::Drawing::Size(196, 29);
            this->txthaslo->TabIndex = 5;
            this->txthaslo->Text = L"Has³o";
            this->txthaslo->Click += gcnew System::EventHandler(this, &Logowanie::txthaslo_Click);
            // 
            // zdjUzytkownik
            // 
            this->zdjUzytkownik->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"zdjUzytkownik.Image")));
            this->zdjUzytkownik->Location = System::Drawing::Point(30, 41);
            this->zdjUzytkownik->Name = L"zdjUzytkownik";
            this->zdjUzytkownik->Size = System::Drawing::Size(32, 29);
            this->zdjUzytkownik->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->zdjUzytkownik->TabIndex = 6;
            this->zdjUzytkownik->TabStop = false;
            // 
            // zdjHaslo
            // 
            this->zdjHaslo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"zdjHaslo.Image")));
            this->zdjHaslo->Location = System::Drawing::Point(30, 89);
            this->zdjHaslo->Name = L"zdjHaslo";
            this->zdjHaslo->Size = System::Drawing::Size(32, 29);
            this->zdjHaslo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->zdjHaslo->TabIndex = 7;
            this->zdjHaslo->TabStop = false;
            // 
            // Logowanie
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->BackColor = System::Drawing::Color::CornflowerBlue;
            this->ClientSize = System::Drawing::Size(309, 212);
            this->Controls->Add(this->zdjHaslo);
            this->Controls->Add(this->zdjUzytkownik);
            this->Controls->Add(this->txthaslo);
            this->Controls->Add(this->txtuzytkownik);
            this->Controls->Add(this->logowanieAnuluj);
            this->Controls->Add(this->logowanieZaloguj);
            this->MaximizeBox = false;
            this->Name = L"Logowanie";
            this->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->ShowIcon = false;
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Logowanie";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zdjUzytkownik))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zdjHaslo))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void logowanieAnuluj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void logowanieZaloguj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void txtuzytkownik_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void txthaslo_Click(System::Object^  sender, System::EventArgs^  e);
    };
}
