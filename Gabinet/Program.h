#pragma once

namespace Gabinet {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;
    /// <summary>
    /// Summary for Program
    /// </summary>
    public ref class Program : public System::Windows::Forms::Form
    {
    public:
        int id_uzytkownika;
    private: System::Windows::Forms::PictureBox^  pb2;
    private: System::Windows::Forms::PictureBox^  pb1;
    private: System::Windows::Forms::Button^  pracownicySzukaj;
    private: System::Windows::Forms::TextBox^  txtPszukaj;
    private: System::Windows::Forms::Label^  pracownicyPracownik;
    private: System::Windows::Forms::DataGridView^  pracownicySiatka;
    private: System::Windows::Forms::GroupBox^  danePracownika;
    private: System::Windows::Forms::TextBox^  txtPlogin;
    private: System::Windows::Forms::TextBox^  txtPnazwisko;
    private: System::Windows::Forms::Label^  pracownicyLogin;
    private: System::Windows::Forms::Label^  pracownicyNazwisko;
    private: System::Windows::Forms::TextBox^  txtPimie;
    private: System::Windows::Forms::Label^  pracownicyImie;
    private: System::Windows::Forms::CheckBox^  cbPpracownik;
    private: System::Windows::Forms::Button^  pracownicyDodaj;
    private: System::Windows::Forms::Button^  pracownicyModyfikuj;
    private: System::Windows::Forms::Button^  pracownicyUsun;
    private: System::Windows::Forms::GroupBox^  godzinyPracy;
    private: System::Windows::Forms::GroupBox^  szablonyGodzin;
    private: System::Windows::Forms::Button^  czas10_18;
    private: System::Windows::Forms::Button^  czas9_17;
    private: System::Windows::Forms::Button^  czas8_16;
    private: System::Windows::Forms::Button^  czas7_15;
    private: System::Windows::Forms::TextBox^  txtPsobk;
    private: System::Windows::Forms::TextBox^  txtPsobp;
    private: System::Windows::Forms::TextBox^  txtPptk;
    private: System::Windows::Forms::TextBox^  txtPptp;
    private: System::Windows::Forms::TextBox^  txtPczwk;
    private: System::Windows::Forms::TextBox^  txtPczwp;
    private: System::Windows::Forms::TextBox^  txtPsrk;
    private: System::Windows::Forms::TextBox^  txtPsrp;
    private: System::Windows::Forms::TextBox^  txtPwtk;
    private: System::Windows::Forms::TextBox^  txtPwtp;
    private: System::Windows::Forms::TextBox^  txtPponk;
    private: System::Windows::Forms::TextBox^  txtPponp;
    private: System::Windows::Forms::Label^  sobota;
    private: System::Windows::Forms::Label^  piatek;
    private: System::Windows::Forms::Label^  czwartek;
    private: System::Windows::Forms::Label^  sroda;
    private: System::Windows::Forms::Label^  wtorek;
    private: System::Windows::Forms::Label^  poniedzia³ek;
    private: System::Windows::Forms::CheckBox^  cbPszablony;
    private: System::Windows::Forms::TabPage^  uslugi;
    private: System::Windows::Forms::Button^  uslugiUsun;
    private: System::Windows::Forms::Button^  uslugiModyfikuj;
    private: System::Windows::Forms::Button^  uslugiDodaj;
    private: System::Windows::Forms::GroupBox^  poleUslugi;
    private: System::Windows::Forms::TextBox^  txtUopis;
    private: System::Windows::Forms::TextBox^  txtUczas;
    private: System::Windows::Forms::TextBox^  txtUcena;
    private: System::Windows::Forms::TextBox^  txtUnazwa;
    private: System::Windows::Forms::Label^  etykietaOpis;
    private: System::Windows::Forms::Label^  etykietaCzas;
    private: System::Windows::Forms::Label^  etykietaCena;
    private: System::Windows::Forms::Label^  etykietaNazwa;
    private: System::Windows::Forms::DataGridView^  uslugiSiatka;
    private: System::Windows::Forms::Button^  uslugiSzukaj;
    private: System::Windows::Forms::TextBox^  txtUwyszukaj;
    private: System::Windows::Forms::Label^  etykietaZabieg;
    private: System::Windows::Forms::TabPage^  pracownik_uslugi;
    private: System::Windows::Forms::Label^  etykietaDodajUsluge;
    private: System::Windows::Forms::DataGridView^  siatkaDodajUsluge;
    private: System::Windows::Forms::Label^  etykietaUslugi;
    private: System::Windows::Forms::DataGridView^  siatkaPokazUsluge;
    private: System::Windows::Forms::Label^  etykietaPracownicy;
    private: System::Windows::Forms::DataGridView^  siatkaPUpracownik;
    private: System::Windows::Forms::Button^  pracownik_uslugiSzukaj;
    private: System::Windows::Forms::TextBox^  txtPUszukaj;
    private: System::Windows::Forms::Label^  etykietaPracownik;
    private: System::Windows::Forms::TextBox^  txtPUnazwisko;
    private: System::Windows::Forms::TextBox^  txtPUimie;
    private: System::Windows::Forms::Label^  etykietaNazwisko;
    private: System::Windows::Forms::Label^  etykietaImie;
    private: System::Windows::Forms::TabPage^  klienci;
    private: System::Windows::Forms::Button^  klientUsun;
    private: System::Windows::Forms::Button^  klientModyfikuj;
    private: System::Windows::Forms::Button^  klientDodaj;
    private: System::Windows::Forms::GroupBox^  daneKlienta;
    private: System::Windows::Forms::MaskedTextBox^  txtKkod_pocztowy;
    private: System::Windows::Forms::TextBox^  txtKmiejscowosc;
    private: System::Windows::Forms::Label^  label32;
    private: System::Windows::Forms::Label^  label31;
    private: System::Windows::Forms::TextBox^  txtKnumer;
    private: System::Windows::Forms::Label^  label30;
    private: System::Windows::Forms::TextBox^  txtKulica;
    private: System::Windows::Forms::Label^  label29;
    private: System::Windows::Forms::Label^  label28;
    private: System::Windows::Forms::TextBox^  txtKemail;
    private: System::Windows::Forms::Label^  label27;
    private: System::Windows::Forms::TextBox^  txtKnazwisko;
    private: System::Windows::Forms::Label^  label26;
    private: System::Windows::Forms::TextBox^  txtKimie;
    private: System::Windows::Forms::Label^  label25;
    private: System::Windows::Forms::DataGridView^  siatkaKklient;
    private: System::Windows::Forms::Button^  BTKszukaj;
    private: System::Windows::Forms::TextBox^  txtKszukaj;
    private: System::Windows::Forms::Label^  etykietaKklient;
    private: System::Windows::Forms::MaskedTextBox^  txtKtelefon;
    private: System::Windows::Forms::TabPage^  rezerwacja;
    private: System::Windows::Forms::Label^  etykietaRtermin;
    private: System::Windows::Forms::Label^  etykietaRusluga;
    private: System::Windows::Forms::Label^  etykietaRklient;
    private: System::Windows::Forms::TextBox^  txtRuslugi;
    private: System::Windows::Forms::TextBox^  txtRtermin;
    private: System::Windows::Forms::TextBox^  txtRklient;
    private: System::Windows::Forms::DataGridView^  siatkaRpracownik;
    private: System::Windows::Forms::Button^  rezerwacjaPszukaj;
    private: System::Windows::Forms::TextBox^  txtRszukajP;
    private: System::Windows::Forms::Label^  etykietaRpracownicy;
    private: System::Windows::Forms::MonthCalendar^  kalendarz;
    private: System::Windows::Forms::GroupBox^  godziny;
    private: System::Windows::Forms::DataGridView^  siatkaRklient;
    private: System::Windows::Forms::Button^  rezerwacjaKszukaj;
    private: System::Windows::Forms::TextBox^  txtRszukajK;
    private: System::Windows::Forms::Label^  etykietaRklienci;
    private: System::Windows::Forms::DataGridView^  siatkaRuslugi;
    private: System::Windows::Forms::Button^  rezerwacjaUszukaj;
    private: System::Windows::Forms::TextBox^  txtRszukajU;
    private: System::Windows::Forms::Label^  etykietaRuslugi;
    private: System::Windows::Forms::Button^  rezerwacjaUsun;
    private: System::Windows::Forms::Button^  rezerwacjaModyfikuj;
    private: System::Windows::Forms::Button^  rezerwacjaDodaj;
    private: System::Windows::Forms::ToolStrip^  pasekMenu;
    private: System::Windows::Forms::ToolStripButton^  menuRezerwacja;
    private: System::Windows::Forms::ToolStripButton^  menuKlienci;
    private: System::Windows::Forms::ToolStripButton^  menuPracownicy;
    private: System::Windows::Forms::ToolStripButton^  menuUslugi;
    private: System::Windows::Forms::ToolStripButton^  menuPraca;
    private: System::Windows::Forms::ToolStripButton^  menuUstawienia;
    private: System::Windows::Forms::PictureBox^  pictureBox1;
    public:
        String^ data;
        String^ godzina;
        String^ konfiguracja = L"datasource = localhost; port = 3306; username = root; password = ***; database = gabinet";
        Program(int uzytkownik)
        {
            InitializeComponent();
            id_uzytkownika = uzytkownik;
            //
            //TODO: Add the constructor code here
            //
        }
    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Program()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::TabControl^  kontrola;
    private: System::Windows::Forms::TabPage^  pracownicy;
    private: System::Windows::Forms::TabPage^  zmiana_hasla;
    private: System::Windows::Forms::GroupBox^  groupBox1;
    private: System::Windows::Forms::TextBox^  txtstarehaslo;
    private: System::Windows::Forms::Button^  BTzatwierdz;
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::TextBox^  txtpowtorzhaslo;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::TextBox^  txtnowehaslo;
    private: System::Windows::Forms::Label^  label3;
    private: System::ComponentModel::IContainer^  components;
    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Program::typeid));
            this->kontrola = (gcnew System::Windows::Forms::TabControl());
            this->rezerwacja = (gcnew System::Windows::Forms::TabPage());
            this->rezerwacjaUsun = (gcnew System::Windows::Forms::Button());
            this->rezerwacjaModyfikuj = (gcnew System::Windows::Forms::Button());
            this->rezerwacjaDodaj = (gcnew System::Windows::Forms::Button());
            this->etykietaRtermin = (gcnew System::Windows::Forms::Label());
            this->etykietaRusluga = (gcnew System::Windows::Forms::Label());
            this->etykietaRklient = (gcnew System::Windows::Forms::Label());
            this->txtRuslugi = (gcnew System::Windows::Forms::TextBox());
            this->txtRtermin = (gcnew System::Windows::Forms::TextBox());
            this->txtRklient = (gcnew System::Windows::Forms::TextBox());
            this->siatkaRpracownik = (gcnew System::Windows::Forms::DataGridView());
            this->rezerwacjaPszukaj = (gcnew System::Windows::Forms::Button());
            this->txtRszukajP = (gcnew System::Windows::Forms::TextBox());
            this->etykietaRpracownicy = (gcnew System::Windows::Forms::Label());
            this->kalendarz = (gcnew System::Windows::Forms::MonthCalendar());
            this->godziny = (gcnew System::Windows::Forms::GroupBox());
            this->siatkaRklient = (gcnew System::Windows::Forms::DataGridView());
            this->rezerwacjaKszukaj = (gcnew System::Windows::Forms::Button());
            this->txtRszukajK = (gcnew System::Windows::Forms::TextBox());
            this->etykietaRklienci = (gcnew System::Windows::Forms::Label());
            this->siatkaRuslugi = (gcnew System::Windows::Forms::DataGridView());
            this->rezerwacjaUszukaj = (gcnew System::Windows::Forms::Button());
            this->txtRszukajU = (gcnew System::Windows::Forms::TextBox());
            this->etykietaRuslugi = (gcnew System::Windows::Forms::Label());
            this->klienci = (gcnew System::Windows::Forms::TabPage());
            this->klientUsun = (gcnew System::Windows::Forms::Button());
            this->klientModyfikuj = (gcnew System::Windows::Forms::Button());
            this->klientDodaj = (gcnew System::Windows::Forms::Button());
            this->daneKlienta = (gcnew System::Windows::Forms::GroupBox());
            this->txtKtelefon = (gcnew System::Windows::Forms::MaskedTextBox());
            this->txtKkod_pocztowy = (gcnew System::Windows::Forms::MaskedTextBox());
            this->txtKmiejscowosc = (gcnew System::Windows::Forms::TextBox());
            this->label32 = (gcnew System::Windows::Forms::Label());
            this->label31 = (gcnew System::Windows::Forms::Label());
            this->txtKnumer = (gcnew System::Windows::Forms::TextBox());
            this->label30 = (gcnew System::Windows::Forms::Label());
            this->txtKulica = (gcnew System::Windows::Forms::TextBox());
            this->label29 = (gcnew System::Windows::Forms::Label());
            this->label28 = (gcnew System::Windows::Forms::Label());
            this->txtKemail = (gcnew System::Windows::Forms::TextBox());
            this->label27 = (gcnew System::Windows::Forms::Label());
            this->txtKnazwisko = (gcnew System::Windows::Forms::TextBox());
            this->label26 = (gcnew System::Windows::Forms::Label());
            this->txtKimie = (gcnew System::Windows::Forms::TextBox());
            this->label25 = (gcnew System::Windows::Forms::Label());
            this->siatkaKklient = (gcnew System::Windows::Forms::DataGridView());
            this->BTKszukaj = (gcnew System::Windows::Forms::Button());
            this->txtKszukaj = (gcnew System::Windows::Forms::TextBox());
            this->etykietaKklient = (gcnew System::Windows::Forms::Label());
            this->pracownicy = (gcnew System::Windows::Forms::TabPage());
            this->godzinyPracy = (gcnew System::Windows::Forms::GroupBox());
            this->cbPszablony = (gcnew System::Windows::Forms::CheckBox());
            this->szablonyGodzin = (gcnew System::Windows::Forms::GroupBox());
            this->czas10_18 = (gcnew System::Windows::Forms::Button());
            this->czas9_17 = (gcnew System::Windows::Forms::Button());
            this->czas8_16 = (gcnew System::Windows::Forms::Button());
            this->czas7_15 = (gcnew System::Windows::Forms::Button());
            this->txtPsobk = (gcnew System::Windows::Forms::TextBox());
            this->txtPsobp = (gcnew System::Windows::Forms::TextBox());
            this->txtPptk = (gcnew System::Windows::Forms::TextBox());
            this->txtPptp = (gcnew System::Windows::Forms::TextBox());
            this->txtPczwk = (gcnew System::Windows::Forms::TextBox());
            this->txtPczwp = (gcnew System::Windows::Forms::TextBox());
            this->txtPsrk = (gcnew System::Windows::Forms::TextBox());
            this->txtPsrp = (gcnew System::Windows::Forms::TextBox());
            this->txtPwtk = (gcnew System::Windows::Forms::TextBox());
            this->txtPwtp = (gcnew System::Windows::Forms::TextBox());
            this->txtPponk = (gcnew System::Windows::Forms::TextBox());
            this->txtPponp = (gcnew System::Windows::Forms::TextBox());
            this->sobota = (gcnew System::Windows::Forms::Label());
            this->piatek = (gcnew System::Windows::Forms::Label());
            this->czwartek = (gcnew System::Windows::Forms::Label());
            this->sroda = (gcnew System::Windows::Forms::Label());
            this->wtorek = (gcnew System::Windows::Forms::Label());
            this->poniedzia³ek = (gcnew System::Windows::Forms::Label());
            this->pracownicyDodaj = (gcnew System::Windows::Forms::Button());
            this->danePracownika = (gcnew System::Windows::Forms::GroupBox());
            this->txtPlogin = (gcnew System::Windows::Forms::TextBox());
            this->txtPnazwisko = (gcnew System::Windows::Forms::TextBox());
            this->pracownicyLogin = (gcnew System::Windows::Forms::Label());
            this->pracownicyNazwisko = (gcnew System::Windows::Forms::Label());
            this->txtPimie = (gcnew System::Windows::Forms::TextBox());
            this->pracownicyImie = (gcnew System::Windows::Forms::Label());
            this->cbPpracownik = (gcnew System::Windows::Forms::CheckBox());
            this->pracownicyModyfikuj = (gcnew System::Windows::Forms::Button());
            this->pracownicySzukaj = (gcnew System::Windows::Forms::Button());
            this->txtPszukaj = (gcnew System::Windows::Forms::TextBox());
            this->pracownicyUsun = (gcnew System::Windows::Forms::Button());
            this->pracownicyPracownik = (gcnew System::Windows::Forms::Label());
            this->pracownicySiatka = (gcnew System::Windows::Forms::DataGridView());
            this->uslugi = (gcnew System::Windows::Forms::TabPage());
            this->uslugiUsun = (gcnew System::Windows::Forms::Button());
            this->uslugiModyfikuj = (gcnew System::Windows::Forms::Button());
            this->uslugiDodaj = (gcnew System::Windows::Forms::Button());
            this->poleUslugi = (gcnew System::Windows::Forms::GroupBox());
            this->txtUopis = (gcnew System::Windows::Forms::TextBox());
            this->txtUczas = (gcnew System::Windows::Forms::TextBox());
            this->txtUcena = (gcnew System::Windows::Forms::TextBox());
            this->txtUnazwa = (gcnew System::Windows::Forms::TextBox());
            this->etykietaOpis = (gcnew System::Windows::Forms::Label());
            this->etykietaCzas = (gcnew System::Windows::Forms::Label());
            this->etykietaCena = (gcnew System::Windows::Forms::Label());
            this->etykietaNazwa = (gcnew System::Windows::Forms::Label());
            this->uslugiSiatka = (gcnew System::Windows::Forms::DataGridView());
            this->uslugiSzukaj = (gcnew System::Windows::Forms::Button());
            this->txtUwyszukaj = (gcnew System::Windows::Forms::TextBox());
            this->etykietaZabieg = (gcnew System::Windows::Forms::Label());
            this->pracownik_uslugi = (gcnew System::Windows::Forms::TabPage());
            this->txtPUnazwisko = (gcnew System::Windows::Forms::TextBox());
            this->txtPUimie = (gcnew System::Windows::Forms::TextBox());
            this->etykietaNazwisko = (gcnew System::Windows::Forms::Label());
            this->etykietaImie = (gcnew System::Windows::Forms::Label());
            this->etykietaDodajUsluge = (gcnew System::Windows::Forms::Label());
            this->siatkaDodajUsluge = (gcnew System::Windows::Forms::DataGridView());
            this->etykietaUslugi = (gcnew System::Windows::Forms::Label());
            this->siatkaPokazUsluge = (gcnew System::Windows::Forms::DataGridView());
            this->etykietaPracownicy = (gcnew System::Windows::Forms::Label());
            this->siatkaPUpracownik = (gcnew System::Windows::Forms::DataGridView());
            this->pracownik_uslugiSzukaj = (gcnew System::Windows::Forms::Button());
            this->txtPUszukaj = (gcnew System::Windows::Forms::TextBox());
            this->etykietaPracownik = (gcnew System::Windows::Forms::Label());
            this->zmiana_hasla = (gcnew System::Windows::Forms::TabPage());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->pb2 = (gcnew System::Windows::Forms::PictureBox());
            this->pb1 = (gcnew System::Windows::Forms::PictureBox());
            this->txtstarehaslo = (gcnew System::Windows::Forms::TextBox());
            this->BTzatwierdz = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->txtpowtorzhaslo = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->txtnowehaslo = (gcnew System::Windows::Forms::TextBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->pasekMenu = (gcnew System::Windows::Forms::ToolStrip());
            this->menuRezerwacja = (gcnew System::Windows::Forms::ToolStripButton());
            this->menuKlienci = (gcnew System::Windows::Forms::ToolStripButton());
            this->menuPracownicy = (gcnew System::Windows::Forms::ToolStripButton());
            this->menuUslugi = (gcnew System::Windows::Forms::ToolStripButton());
            this->menuPraca = (gcnew System::Windows::Forms::ToolStripButton());
            this->menuUstawienia = (gcnew System::Windows::Forms::ToolStripButton());
            this->kontrola->SuspendLayout();
            this->rezerwacja->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->siatkaRpracownik))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->siatkaRklient))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->siatkaRuslugi))->BeginInit();
            this->klienci->SuspendLayout();
            this->daneKlienta->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->siatkaKklient))->BeginInit();
            this->pracownicy->SuspendLayout();
            this->godzinyPracy->SuspendLayout();
            this->szablonyGodzin->SuspendLayout();
            this->danePracownika->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pracownicySiatka))->BeginInit();
            this->uslugi->SuspendLayout();
            this->poleUslugi->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->uslugiSiatka))->BeginInit();
            this->pracownik_uslugi->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->siatkaDodajUsluge))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->siatkaPokazUsluge))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->siatkaPUpracownik))->BeginInit();
            this->zmiana_hasla->SuspendLayout();
            this->groupBox1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1))->BeginInit();
            this->pasekMenu->SuspendLayout();
            this->SuspendLayout();
            // 
            // kontrola
            // 
            this->kontrola->Alignment = System::Windows::Forms::TabAlignment::Bottom;
            this->kontrola->Controls->Add(this->rezerwacja);
            this->kontrola->Controls->Add(this->klienci);
            this->kontrola->Controls->Add(this->pracownicy);
            this->kontrola->Controls->Add(this->uslugi);
            this->kontrola->Controls->Add(this->pracownik_uslugi);
            this->kontrola->Controls->Add(this->zmiana_hasla);
            this->kontrola->Location = System::Drawing::Point(24, 93);
            this->kontrola->Name = L"kontrola";
            this->kontrola->SelectedIndex = 0;
            this->kontrola->Size = System::Drawing::Size(764, 428);
            this->kontrola->TabIndex = 0;
            // 
            // rezerwacja
            // 
            this->rezerwacja->Controls->Add(this->rezerwacjaUsun);
            this->rezerwacja->Controls->Add(this->rezerwacjaModyfikuj);
            this->rezerwacja->Controls->Add(this->rezerwacjaDodaj);
            this->rezerwacja->Controls->Add(this->etykietaRtermin);
            this->rezerwacja->Controls->Add(this->etykietaRusluga);
            this->rezerwacja->Controls->Add(this->etykietaRklient);
            this->rezerwacja->Controls->Add(this->txtRuslugi);
            this->rezerwacja->Controls->Add(this->txtRtermin);
            this->rezerwacja->Controls->Add(this->txtRklient);
            this->rezerwacja->Controls->Add(this->siatkaRpracownik);
            this->rezerwacja->Controls->Add(this->rezerwacjaPszukaj);
            this->rezerwacja->Controls->Add(this->txtRszukajP);
            this->rezerwacja->Controls->Add(this->etykietaRpracownicy);
            this->rezerwacja->Controls->Add(this->kalendarz);
            this->rezerwacja->Controls->Add(this->godziny);
            this->rezerwacja->Controls->Add(this->siatkaRklient);
            this->rezerwacja->Controls->Add(this->rezerwacjaKszukaj);
            this->rezerwacja->Controls->Add(this->txtRszukajK);
            this->rezerwacja->Controls->Add(this->etykietaRklienci);
            this->rezerwacja->Controls->Add(this->siatkaRuslugi);
            this->rezerwacja->Controls->Add(this->rezerwacjaUszukaj);
            this->rezerwacja->Controls->Add(this->txtRszukajU);
            this->rezerwacja->Controls->Add(this->etykietaRuslugi);
            this->rezerwacja->Location = System::Drawing::Point(4, 4);
            this->rezerwacja->Name = L"rezerwacja";
            this->rezerwacja->Padding = System::Windows::Forms::Padding(3);
            this->rezerwacja->Size = System::Drawing::Size(756, 402);
            this->rezerwacja->TabIndex = 6;
            this->rezerwacja->Text = L"Rezerwacja";
            this->rezerwacja->UseVisualStyleBackColor = true;
            // 
            // rezerwacjaUsun
            // 
            this->rezerwacjaUsun->BackColor = System::Drawing::Color::Red;
            this->rezerwacjaUsun->Enabled = false;
            this->rezerwacjaUsun->FlatAppearance->BorderSize = 0;
            this->rezerwacjaUsun->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->rezerwacjaUsun->ForeColor = System::Drawing::Color::White;
            this->rezerwacjaUsun->Location = System::Drawing::Point(9, 331);
            this->rezerwacjaUsun->Name = L"rezerwacjaUsun";
            this->rezerwacjaUsun->Size = System::Drawing::Size(75, 23);
            this->rezerwacjaUsun->TabIndex = 25;
            this->rezerwacjaUsun->Text = L"Usuñ";
            this->rezerwacjaUsun->UseVisualStyleBackColor = false;
            this->rezerwacjaUsun->Click += gcnew System::EventHandler(this, &Program::rezerwacjaUsun_Click);
            // 
            // rezerwacjaModyfikuj
            // 
            this->rezerwacjaModyfikuj->BackColor = System::Drawing::Color::Lime;
            this->rezerwacjaModyfikuj->Enabled = false;
            this->rezerwacjaModyfikuj->FlatAppearance->BorderSize = 0;
            this->rezerwacjaModyfikuj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->rezerwacjaModyfikuj->ForeColor = System::Drawing::Color::White;
            this->rezerwacjaModyfikuj->Location = System::Drawing::Point(9, 360);
            this->rezerwacjaModyfikuj->Name = L"rezerwacjaModyfikuj";
            this->rezerwacjaModyfikuj->Size = System::Drawing::Size(157, 23);
            this->rezerwacjaModyfikuj->TabIndex = 24;
            this->rezerwacjaModyfikuj->Text = L"Modyfikuj";
            this->rezerwacjaModyfikuj->UseVisualStyleBackColor = false;
            this->rezerwacjaModyfikuj->Click += gcnew System::EventHandler(this, &Program::rezerwacjaModyfikuj_Click);
            // 
            // rezerwacjaDodaj
            // 
            this->rezerwacjaDodaj->BackColor = System::Drawing::Color::DeepSkyBlue;
            this->rezerwacjaDodaj->FlatAppearance->BorderSize = 0;
            this->rezerwacjaDodaj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->rezerwacjaDodaj->ForeColor = System::Drawing::Color::White;
            this->rezerwacjaDodaj->Location = System::Drawing::Point(90, 331);
            this->rezerwacjaDodaj->Name = L"rezerwacjaDodaj";
            this->rezerwacjaDodaj->Size = System::Drawing::Size(76, 23);
            this->rezerwacjaDodaj->TabIndex = 23;
            this->rezerwacjaDodaj->Text = L"Dodaj";
            this->rezerwacjaDodaj->UseVisualStyleBackColor = false;
            this->rezerwacjaDodaj->Click += gcnew System::EventHandler(this, &Program::rezerwacjaDodaj_Click);
            // 
            // etykietaRtermin
            // 
            this->etykietaRtermin->AutoSize = true;
            this->etykietaRtermin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->etykietaRtermin->Location = System::Drawing::Point(6, 268);
            this->etykietaRtermin->Name = L"etykietaRtermin";
            this->etykietaRtermin->Size = System::Drawing::Size(53, 16);
            this->etykietaRtermin->TabIndex = 22;
            this->etykietaRtermin->Text = L"Termin:";
            // 
            // etykietaRusluga
            // 
            this->etykietaRusluga->AutoSize = true;
            this->etykietaRusluga->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->etykietaRusluga->Location = System::Drawing::Point(6, 226);
            this->etykietaRusluga->Name = L"etykietaRusluga";
            this->etykietaRusluga->Size = System::Drawing::Size(52, 16);
            this->etykietaRusluga->TabIndex = 21;
            this->etykietaRusluga->Text = L"Us³ugi:";
            // 
            // etykietaRklient
            // 
            this->etykietaRklient->AutoSize = true;
            this->etykietaRklient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->etykietaRklient->Location = System::Drawing::Point(6, 184);
            this->etykietaRklient->Name = L"etykietaRklient";
            this->etykietaRklient->Size = System::Drawing::Size(43, 16);
            this->etykietaRklient->TabIndex = 20;
            this->etykietaRklient->Text = L"Klient:";
            // 
            // txtRuslugi
            // 
            this->txtRuslugi->Location = System::Drawing::Point(9, 245);
            this->txtRuslugi->Name = L"txtRuslugi";
            this->txtRuslugi->Size = System::Drawing::Size(157, 20);
            this->txtRuslugi->TabIndex = 17;
            // 
            // txtRtermin
            // 
            this->txtRtermin->Location = System::Drawing::Point(9, 287);
            this->txtRtermin->Name = L"txtRtermin";
            this->txtRtermin->Size = System::Drawing::Size(157, 20);
            this->txtRtermin->TabIndex = 19;
            // 
            // txtRklient
            // 
            this->txtRklient->Location = System::Drawing::Point(9, 203);
            this->txtRklient->Name = L"txtRklient";
            this->txtRklient->Size = System::Drawing::Size(157, 20);
            this->txtRklient->TabIndex = 15;
            // 
            // siatkaRpracownik
            // 
            this->siatkaRpracownik->AllowUserToAddRows = false;
            this->siatkaRpracownik->AllowUserToDeleteRows = false;
            this->siatkaRpracownik->AllowUserToOrderColumns = true;
            this->siatkaRpracownik->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->siatkaRpracownik->BackgroundColor = System::Drawing::Color::White;
            this->siatkaRpracownik->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->siatkaRpracownik->Location = System::Drawing::Point(329, 296);
            this->siatkaRpracownik->Name = L"siatkaRpracownik";
            this->siatkaRpracownik->ReadOnly = true;
            this->siatkaRpracownik->Size = System::Drawing::Size(427, 88);
            this->siatkaRpracownik->TabIndex = 13;
            this->siatkaRpracownik->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::siatkaRpracownik_CellClick);
            // 
            // rezerwacjaPszukaj
            // 
            this->rezerwacjaPszukaj->BackColor = System::Drawing::Color::Orange;
            this->rezerwacjaPszukaj->FlatAppearance->BorderSize = 0;
            this->rezerwacjaPszukaj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->rezerwacjaPszukaj->ForeColor = System::Drawing::Color::White;
            this->rezerwacjaPszukaj->Location = System::Drawing::Point(622, 263);
            this->rezerwacjaPszukaj->Name = L"rezerwacjaPszukaj";
            this->rezerwacjaPszukaj->Size = System::Drawing::Size(92, 23);
            this->rezerwacjaPszukaj->TabIndex = 12;
            this->rezerwacjaPszukaj->Text = L"Szukaj";
            this->rezerwacjaPszukaj->UseVisualStyleBackColor = false;
            this->rezerwacjaPszukaj->Click += gcnew System::EventHandler(this, &Program::rezerwacjaPszukaj_Click);
            // 
            // txtRszukajP
            // 
            this->txtRszukajP->Location = System::Drawing::Point(403, 265);
            this->txtRszukajP->Name = L"txtRszukajP";
            this->txtRszukajP->Size = System::Drawing::Size(190, 20);
            this->txtRszukajP->TabIndex = 11;
            // 
            // etykietaRpracownicy
            // 
            this->etykietaRpracownicy->AutoSize = true;
            this->etykietaRpracownicy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
            this->etykietaRpracownicy->Location = System::Drawing::Point(326, 270);
            this->etykietaRpracownicy->Name = L"etykietaRpracownicy";
            this->etykietaRpracownicy->Size = System::Drawing::Size(73, 16);
            this->etykietaRpracownicy->TabIndex = 10;
            this->etykietaRpracownicy->Text = L"Pracownik:";
            // 
            // kalendarz
            // 
            this->kalendarz->Enabled = false;
            this->kalendarz->Location = System::Drawing::Point(9, 9);
            this->kalendarz->Name = L"kalendarz";
            this->kalendarz->TabIndex = 9;
            this->kalendarz->DateSelected += gcnew System::Windows::Forms::DateRangeEventHandler(this, &Program::kalendarz_DateSelected);
            // 
            // godziny
            // 
            this->godziny->Location = System::Drawing::Point(178, 9);
            this->godziny->Name = L"godziny";
            this->godziny->Size = System::Drawing::Size(145, 376);
            this->godziny->TabIndex = 8;
            this->godziny->TabStop = false;
            this->godziny->Text = L"Godziny";
            // 
            // siatkaRklient
            // 
            this->siatkaRklient->AllowUserToAddRows = false;
            this->siatkaRklient->AllowUserToDeleteRows = false;
            this->siatkaRklient->AllowUserToOrderColumns = true;
            this->siatkaRklient->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->siatkaRklient->BackgroundColor = System::Drawing::Color::White;
            this->siatkaRklient->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->siatkaRklient->Location = System::Drawing::Point(329, 35);
            this->siatkaRklient->Name = L"siatkaRklient";
            this->siatkaRklient->ReadOnly = true;
            this->siatkaRklient->Size = System::Drawing::Size(424, 90);
            this->siatkaRklient->TabIndex = 7;
            this->siatkaRklient->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::siatkaRklient_CellClick);
            // 
            // rezerwacjaKszukaj
            // 
            this->rezerwacjaKszukaj->BackColor = System::Drawing::Color::Orange;
            this->rezerwacjaKszukaj->FlatAppearance->BorderSize = 0;
            this->rezerwacjaKszukaj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->rezerwacjaKszukaj->ForeColor = System::Drawing::Color::White;
            this->rezerwacjaKszukaj->Location = System::Drawing::Point(622, 7);
            this->rezerwacjaKszukaj->Name = L"rezerwacjaKszukaj";
            this->rezerwacjaKszukaj->Size = System::Drawing::Size(92, 23);
            this->rezerwacjaKszukaj->TabIndex = 6;
            this->rezerwacjaKszukaj->Text = L"Szukaj";
            this->rezerwacjaKszukaj->UseVisualStyleBackColor = false;
            this->rezerwacjaKszukaj->Click += gcnew System::EventHandler(this, &Program::rezerwacjaKszukaj_Click);
            // 
            // txtRszukajK
            // 
            this->txtRszukajK->Location = System::Drawing::Point(403, 9);
            this->txtRszukajK->Name = L"txtRszukajK";
            this->txtRszukajK->Size = System::Drawing::Size(190, 20);
            this->txtRszukajK->TabIndex = 5;
            // 
            // etykietaRklienci
            // 
            this->etykietaRklienci->AutoSize = true;
            this->etykietaRklienci->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
            this->etykietaRklienci->Location = System::Drawing::Point(329, 12);
            this->etykietaRklienci->Name = L"etykietaRklienci";
            this->etykietaRklienci->Size = System::Drawing::Size(43, 16);
            this->etykietaRklienci->TabIndex = 4;
            this->etykietaRklienci->Text = L"Klient:";
            // 
            // siatkaRuslugi
            // 
            this->siatkaRuslugi->AllowUserToAddRows = false;
            this->siatkaRuslugi->AllowUserToDeleteRows = false;
            this->siatkaRuslugi->AllowUserToOrderColumns = true;
            this->siatkaRuslugi->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->siatkaRuslugi->BackgroundColor = System::Drawing::Color::White;
            this->siatkaRuslugi->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->siatkaRuslugi->Location = System::Drawing::Point(329, 165);
            this->siatkaRuslugi->Name = L"siatkaRuslugi";
            this->siatkaRuslugi->ReadOnly = true;
            this->siatkaRuslugi->Size = System::Drawing::Size(427, 87);
            this->siatkaRuslugi->TabIndex = 3;
            this->siatkaRuslugi->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::siatkaRuslugi_CellClick);
            // 
            // rezerwacjaUszukaj
            // 
            this->rezerwacjaUszukaj->BackColor = System::Drawing::Color::Orange;
            this->rezerwacjaUszukaj->FlatAppearance->BorderSize = 0;
            this->rezerwacjaUszukaj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->rezerwacjaUszukaj->ForeColor = System::Drawing::Color::White;
            this->rezerwacjaUszukaj->Location = System::Drawing::Point(622, 133);
            this->rezerwacjaUszukaj->Name = L"rezerwacjaUszukaj";
            this->rezerwacjaUszukaj->Size = System::Drawing::Size(92, 23);
            this->rezerwacjaUszukaj->TabIndex = 2;
            this->rezerwacjaUszukaj->Text = L"Szukaj";
            this->rezerwacjaUszukaj->UseVisualStyleBackColor = false;
            this->rezerwacjaUszukaj->Click += gcnew System::EventHandler(this, &Program::rezerwacjaUszukaj_Click);
            // 
            // txtRszukajU
            // 
            this->txtRszukajU->Location = System::Drawing::Point(403, 135);
            this->txtRszukajU->Name = L"txtRszukajU";
            this->txtRszukajU->Size = System::Drawing::Size(190, 20);
            this->txtRszukajU->TabIndex = 1;
            // 
            // etykietaRuslugi
            // 
            this->etykietaRuslugi->AutoSize = true;
            this->etykietaRuslugi->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->etykietaRuslugi->Location = System::Drawing::Point(326, 140);
            this->etykietaRuslugi->Name = L"etykietaRuslugi";
            this->etykietaRuslugi->Size = System::Drawing::Size(52, 16);
            this->etykietaRuslugi->TabIndex = 0;
            this->etykietaRuslugi->Text = L"Us³ugi:";
            // 
            // klienci
            // 
            this->klienci->Controls->Add(this->klientUsun);
            this->klienci->Controls->Add(this->klientModyfikuj);
            this->klienci->Controls->Add(this->klientDodaj);
            this->klienci->Controls->Add(this->daneKlienta);
            this->klienci->Controls->Add(this->siatkaKklient);
            this->klienci->Controls->Add(this->BTKszukaj);
            this->klienci->Controls->Add(this->txtKszukaj);
            this->klienci->Controls->Add(this->etykietaKklient);
            this->klienci->Location = System::Drawing::Point(4, 4);
            this->klienci->Name = L"klienci";
            this->klienci->Padding = System::Windows::Forms::Padding(3);
            this->klienci->Size = System::Drawing::Size(756, 402);
            this->klienci->TabIndex = 5;
            this->klienci->Text = L"Klienci";
            this->klienci->UseVisualStyleBackColor = true;
            // 
            // klientUsun
            // 
            this->klientUsun->BackColor = System::Drawing::Color::Red;
            this->klientUsun->Enabled = false;
            this->klientUsun->FlatAppearance->BorderSize = 0;
            this->klientUsun->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->klientUsun->ForeColor = System::Drawing::Color::White;
            this->klientUsun->Location = System::Drawing::Point(107, 367);
            this->klientUsun->Name = L"klientUsun";
            this->klientUsun->Size = System::Drawing::Size(133, 23);
            this->klientUsun->TabIndex = 7;
            this->klientUsun->Text = L"Usuñ";
            this->klientUsun->UseVisualStyleBackColor = false;
            this->klientUsun->Click += gcnew System::EventHandler(this, &Program::klientUsun_Click);
            // 
            // klientModyfikuj
            // 
            this->klientModyfikuj->BackColor = System::Drawing::Color::Lime;
            this->klientModyfikuj->Enabled = false;
            this->klientModyfikuj->FlatAppearance->BorderSize = 0;
            this->klientModyfikuj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->klientModyfikuj->ForeColor = System::Drawing::Color::White;
            this->klientModyfikuj->Location = System::Drawing::Point(293, 367);
            this->klientModyfikuj->Name = L"klientModyfikuj";
            this->klientModyfikuj->Size = System::Drawing::Size(133, 23);
            this->klientModyfikuj->TabIndex = 6;
            this->klientModyfikuj->Text = L"Modyfikuj";
            this->klientModyfikuj->UseVisualStyleBackColor = false;
            this->klientModyfikuj->Click += gcnew System::EventHandler(this, &Program::klientModyfikuj_Click);
            // 
            // klientDodaj
            // 
            this->klientDodaj->BackColor = System::Drawing::Color::DeepSkyBlue;
            this->klientDodaj->FlatAppearance->BorderSize = 0;
            this->klientDodaj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->klientDodaj->ForeColor = System::Drawing::Color::White;
            this->klientDodaj->Location = System::Drawing::Point(473, 367);
            this->klientDodaj->Name = L"klientDodaj";
            this->klientDodaj->Size = System::Drawing::Size(133, 23);
            this->klientDodaj->TabIndex = 5;
            this->klientDodaj->Text = L"Dodaj";
            this->klientDodaj->UseVisualStyleBackColor = false;
            this->klientDodaj->Click += gcnew System::EventHandler(this, &Program::klientDodaj_Click);
            // 
            // daneKlienta
            // 
            this->daneKlienta->Controls->Add(this->txtKtelefon);
            this->daneKlienta->Controls->Add(this->txtKkod_pocztowy);
            this->daneKlienta->Controls->Add(this->txtKmiejscowosc);
            this->daneKlienta->Controls->Add(this->label32);
            this->daneKlienta->Controls->Add(this->label31);
            this->daneKlienta->Controls->Add(this->txtKnumer);
            this->daneKlienta->Controls->Add(this->label30);
            this->daneKlienta->Controls->Add(this->txtKulica);
            this->daneKlienta->Controls->Add(this->label29);
            this->daneKlienta->Controls->Add(this->label28);
            this->daneKlienta->Controls->Add(this->txtKemail);
            this->daneKlienta->Controls->Add(this->label27);
            this->daneKlienta->Controls->Add(this->txtKnazwisko);
            this->daneKlienta->Controls->Add(this->label26);
            this->daneKlienta->Controls->Add(this->txtKimie);
            this->daneKlienta->Controls->Add(this->label25);
            this->daneKlienta->Location = System::Drawing::Point(0, 183);
            this->daneKlienta->Name = L"daneKlienta";
            this->daneKlienta->Size = System::Drawing::Size(770, 178);
            this->daneKlienta->TabIndex = 4;
            this->daneKlienta->TabStop = false;
            this->daneKlienta->Text = L"Edycja danych klienta";
            // 
            // txtKtelefon
            // 
            this->txtKtelefon->Location = System::Drawing::Point(177, 129);
            this->txtKtelefon->Mask = L"000-000-000";
            this->txtKtelefon->Name = L"txtKtelefon";
            this->txtKtelefon->Size = System::Drawing::Size(147, 20);
            this->txtKtelefon->TabIndex = 19;
            // 
            // txtKkod_pocztowy
            // 
            this->txtKkod_pocztowy->Location = System::Drawing::Point(462, 96);
            this->txtKkod_pocztowy->Mask = L"00-999";
            this->txtKkod_pocztowy->Name = L"txtKkod_pocztowy";
            this->txtKkod_pocztowy->Size = System::Drawing::Size(144, 20);
            this->txtKkod_pocztowy->TabIndex = 1;
            // 
            // txtKmiejscowosc
            // 
            this->txtKmiejscowosc->Location = System::Drawing::Point(462, 123);
            this->txtKmiejscowosc->Name = L"txtKmiejscowosc";
            this->txtKmiejscowosc->Size = System::Drawing::Size(144, 20);
            this->txtKmiejscowosc->TabIndex = 18;
            // 
            // label32
            // 
            this->label32->AutoSize = true;
            this->label32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label32->Location = System::Drawing::Point(361, 129);
            this->label32->Name = L"label32";
            this->label32->Size = System::Drawing::Size(86, 16);
            this->label32->TabIndex = 17;
            this->label32->Text = L"Miejscowoœæ";
            // 
            // label31
            // 
            this->label31->AutoSize = true;
            this->label31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label31->Location = System::Drawing::Point(361, 103);
            this->label31->Name = L"label31";
            this->label31->Size = System::Drawing::Size(94, 16);
            this->label31->TabIndex = 15;
            this->label31->Text = L"Kod pocztowy:";
            // 
            // txtKnumer
            // 
            this->txtKnumer->Location = System::Drawing::Point(462, 70);
            this->txtKnumer->Name = L"txtKnumer";
            this->txtKnumer->Size = System::Drawing::Size(144, 20);
            this->txtKnumer->TabIndex = 14;
            // 
            // label30
            // 
            this->label30->AutoSize = true;
            this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label30->Location = System::Drawing::Point(361, 77);
            this->label30->Name = L"label30";
            this->label30->Size = System::Drawing::Size(51, 16);
            this->label30->TabIndex = 13;
            this->label30->Text = L"Numer:";
            // 
            // txtKulica
            // 
            this->txtKulica->Location = System::Drawing::Point(462, 45);
            this->txtKulica->Name = L"txtKulica";
            this->txtKulica->Size = System::Drawing::Size(144, 20);
            this->txtKulica->TabIndex = 8;
            // 
            // label29
            // 
            this->label29->AutoSize = true;
            this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label29->Location = System::Drawing::Point(361, 48);
            this->label29->Name = L"label29";
            this->label29->Size = System::Drawing::Size(42, 16);
            this->label29->TabIndex = 7;
            this->label29->Text = L"Ulica:";
            // 
            // label28
            // 
            this->label28->AutoSize = true;
            this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label28->Location = System::Drawing::Point(104, 126);
            this->label28->Name = L"label28";
            this->label28->Size = System::Drawing::Size(57, 16);
            this->label28->TabIndex = 11;
            this->label28->Text = L"Telefon:";
            // 
            // txtKemail
            // 
            this->txtKemail->Location = System::Drawing::Point(177, 96);
            this->txtKemail->Name = L"txtKemail";
            this->txtKemail->Size = System::Drawing::Size(147, 20);
            this->txtKemail->TabIndex = 10;
            // 
            // label27
            // 
            this->label27->AutoSize = true;
            this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label27->Location = System::Drawing::Point(104, 100);
            this->label27->Name = L"label27";
            this->label27->Size = System::Drawing::Size(45, 16);
            this->label27->TabIndex = 9;
            this->label27->Text = L"Email:";
            // 
            // txtKnazwisko
            // 
            this->txtKnazwisko->Location = System::Drawing::Point(177, 71);
            this->txtKnazwisko->Name = L"txtKnazwisko";
            this->txtKnazwisko->Size = System::Drawing::Size(147, 20);
            this->txtKnazwisko->TabIndex = 8;
            // 
            // label26
            // 
            this->label26->AutoSize = true;
            this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label26->Location = System::Drawing::Point(104, 74);
            this->label26->Name = L"label26";
            this->label26->Size = System::Drawing::Size(69, 16);
            this->label26->TabIndex = 7;
            this->label26->Text = L"Nazwisko:";
            // 
            // txtKimie
            // 
            this->txtKimie->Location = System::Drawing::Point(177, 45);
            this->txtKimie->Name = L"txtKimie";
            this->txtKimie->Size = System::Drawing::Size(147, 20);
            this->txtKimie->TabIndex = 6;
            // 
            // label25
            // 
            this->label25->AutoSize = true;
            this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label25->Location = System::Drawing::Point(104, 48);
            this->label25->Name = L"label25";
            this->label25->Size = System::Drawing::Size(36, 16);
            this->label25->TabIndex = 5;
            this->label25->Text = L"Imiê:";
            // 
            // siatkaKklient
            // 
            this->siatkaKklient->AllowUserToAddRows = false;
            this->siatkaKklient->AllowUserToDeleteRows = false;
            this->siatkaKklient->AllowUserToOrderColumns = true;
            this->siatkaKklient->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->siatkaKklient->BackgroundColor = System::Drawing::Color::White;
            this->siatkaKklient->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->siatkaKklient->Location = System::Drawing::Point(0, 50);
            this->siatkaKklient->Name = L"siatkaKklient";
            this->siatkaKklient->ReadOnly = true;
            this->siatkaKklient->Size = System::Drawing::Size(756, 127);
            this->siatkaKklient->TabIndex = 3;
            this->siatkaKklient->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::siatkaKklient_CellClick);
            // 
            // BTKszukaj
            // 
            this->BTKszukaj->BackColor = System::Drawing::Color::Orange;
            this->BTKszukaj->FlatAppearance->BorderSize = 0;
            this->BTKszukaj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTKszukaj->ForeColor = System::Drawing::Color::White;
            this->BTKszukaj->Location = System::Drawing::Point(255, 15);
            this->BTKszukaj->Name = L"BTKszukaj";
            this->BTKszukaj->Size = System::Drawing::Size(120, 23);
            this->BTKszukaj->TabIndex = 2;
            this->BTKszukaj->Text = L"Szukaj";
            this->BTKszukaj->UseVisualStyleBackColor = false;
            this->BTKszukaj->Click += gcnew System::EventHandler(this, &Program::klientSzukaj_Click);
            // 
            // txtKszukaj
            // 
            this->txtKszukaj->Location = System::Drawing::Point(67, 17);
            this->txtKszukaj->Name = L"txtKszukaj";
            this->txtKszukaj->Size = System::Drawing::Size(182, 20);
            this->txtKszukaj->TabIndex = 1;
            // 
            // etykietaKklient
            // 
            this->etykietaKklient->AutoSize = true;
            this->etykietaKklient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->etykietaKklient->Location = System::Drawing::Point(18, 18);
            this->etykietaKklient->Name = L"etykietaKklient";
            this->etykietaKklient->Size = System::Drawing::Size(43, 16);
            this->etykietaKklient->TabIndex = 0;
            this->etykietaKklient->Text = L"Klient:";
            // 
            // pracownicy
            // 
            this->pracownicy->Controls->Add(this->godzinyPracy);
            this->pracownicy->Controls->Add(this->pracownicyDodaj);
            this->pracownicy->Controls->Add(this->danePracownika);
            this->pracownicy->Controls->Add(this->pracownicyModyfikuj);
            this->pracownicy->Controls->Add(this->pracownicySzukaj);
            this->pracownicy->Controls->Add(this->txtPszukaj);
            this->pracownicy->Controls->Add(this->pracownicyUsun);
            this->pracownicy->Controls->Add(this->pracownicyPracownik);
            this->pracownicy->Controls->Add(this->pracownicySiatka);
            this->pracownicy->Location = System::Drawing::Point(4, 4);
            this->pracownicy->Name = L"pracownicy";
            this->pracownicy->Padding = System::Windows::Forms::Padding(3);
            this->pracownicy->Size = System::Drawing::Size(756, 402);
            this->pracownicy->TabIndex = 1;
            this->pracownicy->Text = L"Pracownicy";
            this->pracownicy->UseVisualStyleBackColor = true;
            // 
            // godzinyPracy
            // 
            this->godzinyPracy->Controls->Add(this->cbPszablony);
            this->godzinyPracy->Controls->Add(this->szablonyGodzin);
            this->godzinyPracy->Controls->Add(this->txtPsobk);
            this->godzinyPracy->Controls->Add(this->txtPsobp);
            this->godzinyPracy->Controls->Add(this->txtPptk);
            this->godzinyPracy->Controls->Add(this->txtPptp);
            this->godzinyPracy->Controls->Add(this->txtPczwk);
            this->godzinyPracy->Controls->Add(this->txtPczwp);
            this->godzinyPracy->Controls->Add(this->txtPsrk);
            this->godzinyPracy->Controls->Add(this->txtPsrp);
            this->godzinyPracy->Controls->Add(this->txtPwtk);
            this->godzinyPracy->Controls->Add(this->txtPwtp);
            this->godzinyPracy->Controls->Add(this->txtPponk);
            this->godzinyPracy->Controls->Add(this->txtPponp);
            this->godzinyPracy->Controls->Add(this->sobota);
            this->godzinyPracy->Controls->Add(this->piatek);
            this->godzinyPracy->Controls->Add(this->czwartek);
            this->godzinyPracy->Controls->Add(this->sroda);
            this->godzinyPracy->Controls->Add(this->wtorek);
            this->godzinyPracy->Controls->Add(this->poniedzia³ek);
            this->godzinyPracy->Location = System::Drawing::Point(6, 172);
            this->godzinyPracy->Name = L"godzinyPracy";
            this->godzinyPracy->Size = System::Drawing::Size(423, 191);
            this->godzinyPracy->TabIndex = 15;
            this->godzinyPracy->TabStop = false;
            this->godzinyPracy->Text = L"Godziny pracy";
            this->godzinyPracy->Visible = false;
            // 
            // cbPszablony
            // 
            this->cbPszablony->AutoSize = true;
            this->cbPszablony->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->cbPszablony->Location = System::Drawing::Point(262, 24);
            this->cbPszablony->Name = L"cbPszablony";
            this->cbPszablony->Size = System::Drawing::Size(83, 20);
            this->cbPszablony->TabIndex = 19;
            this->cbPszablony->Text = L"Szablony";
            this->cbPszablony->UseVisualStyleBackColor = true;
            this->cbPszablony->CheckedChanged += gcnew System::EventHandler(this, &Program::cbPszablony_CheckedChanged);
            // 
            // szablonyGodzin
            // 
            this->szablonyGodzin->Controls->Add(this->czas10_18);
            this->szablonyGodzin->Controls->Add(this->czas9_17);
            this->szablonyGodzin->Controls->Add(this->czas8_16);
            this->szablonyGodzin->Controls->Add(this->czas7_15);
            this->szablonyGodzin->Location = System::Drawing::Point(262, 52);
            this->szablonyGodzin->Name = L"szablonyGodzin";
            this->szablonyGodzin->Size = System::Drawing::Size(115, 125);
            this->szablonyGodzin->TabIndex = 18;
            this->szablonyGodzin->TabStop = false;
            this->szablonyGodzin->Text = L"Szablony";
            this->szablonyGodzin->Visible = false;
            // 
            // czas10_18
            // 
            this->czas10_18->BackColor = System::Drawing::Color::LightSkyBlue;
            this->czas10_18->FlatAppearance->BorderSize = 0;
            this->czas10_18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->czas10_18->ForeColor = System::Drawing::Color::White;
            this->czas10_18->Location = System::Drawing::Point(20, 96);
            this->czas10_18->Name = L"czas10_18";
            this->czas10_18->Size = System::Drawing::Size(75, 23);
            this->czas10_18->TabIndex = 3;
            this->czas10_18->Text = L"10-18";
            this->czas10_18->UseVisualStyleBackColor = false;
            this->czas10_18->Click += gcnew System::EventHandler(this, &Program::czas10_18_Click);
            // 
            // czas9_17
            // 
            this->czas9_17->BackColor = System::Drawing::Color::LightSkyBlue;
            this->czas9_17->FlatAppearance->BorderSize = 0;
            this->czas9_17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->czas9_17->ForeColor = System::Drawing::Color::White;
            this->czas9_17->Location = System::Drawing::Point(20, 71);
            this->czas9_17->Name = L"czas9_17";
            this->czas9_17->Size = System::Drawing::Size(75, 23);
            this->czas9_17->TabIndex = 2;
            this->czas9_17->Text = L"9-17";
            this->czas9_17->UseVisualStyleBackColor = false;
            this->czas9_17->Click += gcnew System::EventHandler(this, &Program::czas9_17_Click);
            // 
            // czas8_16
            // 
            this->czas8_16->BackColor = System::Drawing::Color::LightSkyBlue;
            this->czas8_16->FlatAppearance->BorderSize = 0;
            this->czas8_16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->czas8_16->ForeColor = System::Drawing::Color::White;
            this->czas8_16->Location = System::Drawing::Point(20, 44);
            this->czas8_16->Name = L"czas8_16";
            this->czas8_16->Size = System::Drawing::Size(75, 23);
            this->czas8_16->TabIndex = 1;
            this->czas8_16->Text = L"8-16";
            this->czas8_16->UseVisualStyleBackColor = false;
            this->czas8_16->Click += gcnew System::EventHandler(this, &Program::czas8_16_Click);
            // 
            // czas7_15
            // 
            this->czas7_15->BackColor = System::Drawing::Color::LightSkyBlue;
            this->czas7_15->FlatAppearance->BorderSize = 0;
            this->czas7_15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->czas7_15->ForeColor = System::Drawing::Color::White;
            this->czas7_15->Location = System::Drawing::Point(20, 17);
            this->czas7_15->Name = L"czas7_15";
            this->czas7_15->Size = System::Drawing::Size(75, 23);
            this->czas7_15->TabIndex = 0;
            this->czas7_15->Text = L"7-15";
            this->czas7_15->UseVisualStyleBackColor = false;
            this->czas7_15->Click += gcnew System::EventHandler(this, &Program::czas7_15_Click);
            // 
            // txtPsobk
            // 
            this->txtPsobk->Location = System::Drawing::Point(181, 158);
            this->txtPsobk->Name = L"txtPsobk";
            this->txtPsobk->Size = System::Drawing::Size(62, 20);
            this->txtPsobk->TabIndex = 17;
            // 
            // txtPsobp
            // 
            this->txtPsobp->Location = System::Drawing::Point(107, 158);
            this->txtPsobp->Name = L"txtPsobp";
            this->txtPsobp->Size = System::Drawing::Size(62, 20);
            this->txtPsobp->TabIndex = 16;
            // 
            // txtPptk
            // 
            this->txtPptk->Location = System::Drawing::Point(181, 133);
            this->txtPptk->Name = L"txtPptk";
            this->txtPptk->Size = System::Drawing::Size(62, 20);
            this->txtPptk->TabIndex = 15;
            // 
            // txtPptp
            // 
            this->txtPptp->Location = System::Drawing::Point(107, 133);
            this->txtPptp->Name = L"txtPptp";
            this->txtPptp->Size = System::Drawing::Size(62, 20);
            this->txtPptp->TabIndex = 14;
            // 
            // txtPczwk
            // 
            this->txtPczwk->Location = System::Drawing::Point(181, 106);
            this->txtPczwk->Name = L"txtPczwk";
            this->txtPczwk->Size = System::Drawing::Size(62, 20);
            this->txtPczwk->TabIndex = 13;
            // 
            // txtPczwp
            // 
            this->txtPczwp->Location = System::Drawing::Point(107, 106);
            this->txtPczwp->Name = L"txtPczwp";
            this->txtPczwp->Size = System::Drawing::Size(62, 20);
            this->txtPczwp->TabIndex = 12;
            // 
            // txtPsrk
            // 
            this->txtPsrk->Location = System::Drawing::Point(181, 79);
            this->txtPsrk->Name = L"txtPsrk";
            this->txtPsrk->Size = System::Drawing::Size(62, 20);
            this->txtPsrk->TabIndex = 11;
            // 
            // txtPsrp
            // 
            this->txtPsrp->Location = System::Drawing::Point(107, 79);
            this->txtPsrp->Name = L"txtPsrp";
            this->txtPsrp->Size = System::Drawing::Size(62, 20);
            this->txtPsrp->TabIndex = 10;
            // 
            // txtPwtk
            // 
            this->txtPwtk->Location = System::Drawing::Point(181, 52);
            this->txtPwtk->Name = L"txtPwtk";
            this->txtPwtk->Size = System::Drawing::Size(62, 20);
            this->txtPwtk->TabIndex = 9;
            // 
            // txtPwtp
            // 
            this->txtPwtp->Location = System::Drawing::Point(107, 52);
            this->txtPwtp->Name = L"txtPwtp";
            this->txtPwtp->Size = System::Drawing::Size(62, 20);
            this->txtPwtp->TabIndex = 8;
            // 
            // txtPponk
            // 
            this->txtPponk->Location = System::Drawing::Point(181, 24);
            this->txtPponk->Name = L"txtPponk";
            this->txtPponk->Size = System::Drawing::Size(62, 20);
            this->txtPponk->TabIndex = 7;
            // 
            // txtPponp
            // 
            this->txtPponp->Location = System::Drawing::Point(107, 24);
            this->txtPponp->Name = L"txtPponp";
            this->txtPponp->Size = System::Drawing::Size(62, 20);
            this->txtPponp->TabIndex = 6;
            // 
            // sobota
            // 
            this->sobota->AutoSize = true;
            this->sobota->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->sobota->Location = System::Drawing::Point(14, 161);
            this->sobota->Name = L"sobota";
            this->sobota->Size = System::Drawing::Size(52, 16);
            this->sobota->TabIndex = 5;
            this->sobota->Text = L"Sobota";
            // 
            // piatek
            // 
            this->piatek->AutoSize = true;
            this->piatek->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->piatek->Location = System::Drawing::Point(14, 136);
            this->piatek->Name = L"piatek";
            this->piatek->Size = System::Drawing::Size(46, 16);
            this->piatek->TabIndex = 4;
            this->piatek->Text = L"Pi¹tek";
            // 
            // czwartek
            // 
            this->czwartek->AutoSize = true;
            this->czwartek->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->czwartek->Location = System::Drawing::Point(14, 109);
            this->czwartek->Name = L"czwartek";
            this->czwartek->Size = System::Drawing::Size(62, 16);
            this->czwartek->TabIndex = 3;
            this->czwartek->Text = L"Czwartek";
            // 
            // sroda
            // 
            this->sroda->AutoSize = true;
            this->sroda->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->sroda->Location = System::Drawing::Point(14, 82);
            this->sroda->Name = L"sroda";
            this->sroda->Size = System::Drawing::Size(45, 16);
            this->sroda->TabIndex = 2;
            this->sroda->Text = L"Œroda";
            // 
            // wtorek
            // 
            this->wtorek->AutoSize = true;
            this->wtorek->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->wtorek->Location = System::Drawing::Point(14, 55);
            this->wtorek->Name = L"wtorek";
            this->wtorek->Size = System::Drawing::Size(51, 16);
            this->wtorek->TabIndex = 1;
            this->wtorek->Text = L"Wtorek";
            // 
            // poniedzia³ek
            // 
            this->poniedzia³ek->AutoSize = true;
            this->poniedzia³ek->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->poniedzia³ek->Location = System::Drawing::Point(14, 27);
            this->poniedzia³ek->Name = L"poniedzia³ek";
            this->poniedzia³ek->Size = System::Drawing::Size(89, 16);
            this->poniedzia³ek->TabIndex = 0;
            this->poniedzia³ek->Text = L"Poniedzia³ek";
            // 
            // pracownicyDodaj
            // 
            this->pracownicyDodaj->BackColor = System::Drawing::Color::DeepSkyBlue;
            this->pracownicyDodaj->FlatAppearance->BorderSize = 0;
            this->pracownicyDodaj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->pracownicyDodaj->ForeColor = System::Drawing::Color::White;
            this->pracownicyDodaj->Location = System::Drawing::Point(268, 369);
            this->pracownicyDodaj->Name = L"pracownicyDodaj";
            this->pracownicyDodaj->Size = System::Drawing::Size(95, 23);
            this->pracownicyDodaj->TabIndex = 14;
            this->pracownicyDodaj->Text = L"Dodaj";
            this->pracownicyDodaj->UseVisualStyleBackColor = false;
            this->pracownicyDodaj->Click += gcnew System::EventHandler(this, &Program::pracownicyDodaj_Click);
            // 
            // danePracownika
            // 
            this->danePracownika->Controls->Add(this->txtPlogin);
            this->danePracownika->Controls->Add(this->txtPnazwisko);
            this->danePracownika->Controls->Add(this->pracownicyLogin);
            this->danePracownika->Controls->Add(this->pracownicyNazwisko);
            this->danePracownika->Controls->Add(this->txtPimie);
            this->danePracownika->Controls->Add(this->pracownicyImie);
            this->danePracownika->Controls->Add(this->cbPpracownik);
            this->danePracownika->Location = System::Drawing::Point(6, 40);
            this->danePracownika->Name = L"danePracownika";
            this->danePracownika->Size = System::Drawing::Size(423, 131);
            this->danePracownika->TabIndex = 4;
            this->danePracownika->TabStop = false;
            this->danePracownika->Text = L"Edycja danych u¿ytkownika";
            // 
            // txtPlogin
            // 
            this->txtPlogin->Location = System::Drawing::Point(85, 95);
            this->txtPlogin->Name = L"txtPlogin";
            this->txtPlogin->Size = System::Drawing::Size(147, 20);
            this->txtPlogin->TabIndex = 11;
            // 
            // txtPnazwisko
            // 
            this->txtPnazwisko->Location = System::Drawing::Point(85, 55);
            this->txtPnazwisko->Name = L"txtPnazwisko";
            this->txtPnazwisko->Size = System::Drawing::Size(147, 20);
            this->txtPnazwisko->TabIndex = 10;
            // 
            // pracownicyLogin
            // 
            this->pracownicyLogin->AutoSize = true;
            this->pracownicyLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->pracownicyLogin->Location = System::Drawing::Point(14, 103);
            this->pracownicyLogin->Name = L"pracownicyLogin";
            this->pracownicyLogin->Size = System::Drawing::Size(44, 16);
            this->pracownicyLogin->TabIndex = 9;
            this->pracownicyLogin->Text = L"Login:";
            // 
            // pracownicyNazwisko
            // 
            this->pracownicyNazwisko->AutoSize = true;
            this->pracownicyNazwisko->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
            this->pracownicyNazwisko->Location = System::Drawing::Point(14, 59);
            this->pracownicyNazwisko->Name = L"pracownicyNazwisko";
            this->pracownicyNazwisko->Size = System::Drawing::Size(69, 16);
            this->pracownicyNazwisko->TabIndex = 8;
            this->pracownicyNazwisko->Text = L"Nazwisko:";
            // 
            // txtPimie
            // 
            this->txtPimie->Location = System::Drawing::Point(85, 19);
            this->txtPimie->Name = L"txtPimie";
            this->txtPimie->Size = System::Drawing::Size(147, 20);
            this->txtPimie->TabIndex = 7;
            // 
            // pracownicyImie
            // 
            this->pracownicyImie->AutoSize = true;
            this->pracownicyImie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->pracownicyImie->Location = System::Drawing::Point(14, 20);
            this->pracownicyImie->Name = L"pracownicyImie";
            this->pracownicyImie->Size = System::Drawing::Size(36, 16);
            this->pracownicyImie->TabIndex = 6;
            this->pracownicyImie->Text = L"Imie:";
            // 
            // cbPpracownik
            // 
            this->cbPpracownik->AutoSize = true;
            this->cbPpracownik->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->cbPpracownik->Location = System::Drawing::Point(245, 19);
            this->cbPpracownik->Name = L"cbPpracownik";
            this->cbPpracownik->Size = System::Drawing::Size(89, 20);
            this->cbPpracownik->TabIndex = 5;
            this->cbPpracownik->Text = L"Pracownik";
            this->cbPpracownik->UseVisualStyleBackColor = true;
            this->cbPpracownik->CheckedChanged += gcnew System::EventHandler(this, &Program::cbPpracownik_CheckedChanged);
            // 
            // pracownicyModyfikuj
            // 
            this->pracownicyModyfikuj->BackColor = System::Drawing::Color::Lime;
            this->pracownicyModyfikuj->Enabled = false;
            this->pracownicyModyfikuj->FlatAppearance->BorderSize = 0;
            this->pracownicyModyfikuj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->pracownicyModyfikuj->ForeColor = System::Drawing::Color::White;
            this->pracownicyModyfikuj->Location = System::Drawing::Point(152, 369);
            this->pracownicyModyfikuj->Name = L"pracownicyModyfikuj";
            this->pracownicyModyfikuj->Size = System::Drawing::Size(86, 23);
            this->pracownicyModyfikuj->TabIndex = 13;
            this->pracownicyModyfikuj->Text = L"Modyfikuj";
            this->pracownicyModyfikuj->UseVisualStyleBackColor = false;
            this->pracownicyModyfikuj->Click += gcnew System::EventHandler(this, &Program::pracownicyModyfikuj_Click);
            // 
            // pracownicySzukaj
            // 
            this->pracownicySzukaj->BackColor = System::Drawing::Color::Orange;
            this->pracownicySzukaj->FlatAppearance->BorderSize = 0;
            this->pracownicySzukaj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->pracownicySzukaj->ForeColor = System::Drawing::Color::White;
            this->pracownicySzukaj->Location = System::Drawing::Point(244, 13);
            this->pracownicySzukaj->Name = L"pracownicySzukaj";
            this->pracownicySzukaj->Size = System::Drawing::Size(83, 21);
            this->pracownicySzukaj->TabIndex = 3;
            this->pracownicySzukaj->Text = L"Szukaj";
            this->pracownicySzukaj->UseVisualStyleBackColor = false;
            this->pracownicySzukaj->Click += gcnew System::EventHandler(this, &Program::pracownicySzukaj_Click);
            // 
            // txtPszukaj
            // 
            this->txtPszukaj->Location = System::Drawing::Point(91, 13);
            this->txtPszukaj->Name = L"txtPszukaj";
            this->txtPszukaj->Size = System::Drawing::Size(147, 20);
            this->txtPszukaj->TabIndex = 2;
            // 
            // pracownicyUsun
            // 
            this->pracownicyUsun->BackColor = System::Drawing::Color::Red;
            this->pracownicyUsun->Enabled = false;
            this->pracownicyUsun->FlatAppearance->BorderSize = 0;
            this->pracownicyUsun->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->pracownicyUsun->ForeColor = System::Drawing::Color::White;
            this->pracownicyUsun->Location = System::Drawing::Point(23, 369);
            this->pracownicyUsun->Name = L"pracownicyUsun";
            this->pracownicyUsun->Size = System::Drawing::Size(86, 23);
            this->pracownicyUsun->TabIndex = 12;
            this->pracownicyUsun->Text = L"Usuñ";
            this->pracownicyUsun->UseVisualStyleBackColor = false;
            this->pracownicyUsun->Click += gcnew System::EventHandler(this, &Program::pracownicyUsun_Click);
            // 
            // pracownicyPracownik
            // 
            this->pracownicyPracownik->AutoSize = true;
            this->pracownicyPracownik->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
            this->pracownicyPracownik->Location = System::Drawing::Point(20, 17);
            this->pracownicyPracownik->Name = L"pracownicyPracownik";
            this->pracownicyPracownik->Size = System::Drawing::Size(73, 16);
            this->pracownicyPracownik->TabIndex = 1;
            this->pracownicyPracownik->Text = L"Pracownik:";
            // 
            // pracownicySiatka
            // 
            this->pracownicySiatka->AllowUserToAddRows = false;
            this->pracownicySiatka->AllowUserToDeleteRows = false;
            this->pracownicySiatka->AllowUserToOrderColumns = true;
            this->pracownicySiatka->BackgroundColor = System::Drawing::Color::White;
            this->pracownicySiatka->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->pracownicySiatka->Location = System::Drawing::Point(432, -4);
            this->pracownicySiatka->Name = L"pracownicySiatka";
            this->pracownicySiatka->ReadOnly = true;
            this->pracownicySiatka->Size = System::Drawing::Size(328, 411);
            this->pracownicySiatka->TabIndex = 0;
            this->pracownicySiatka->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::pracownicySiatka_CellClick);
            // 
            // uslugi
            // 
            this->uslugi->Controls->Add(this->uslugiUsun);
            this->uslugi->Controls->Add(this->uslugiModyfikuj);
            this->uslugi->Controls->Add(this->uslugiDodaj);
            this->uslugi->Controls->Add(this->poleUslugi);
            this->uslugi->Controls->Add(this->uslugiSiatka);
            this->uslugi->Controls->Add(this->uslugiSzukaj);
            this->uslugi->Controls->Add(this->txtUwyszukaj);
            this->uslugi->Controls->Add(this->etykietaZabieg);
            this->uslugi->Location = System::Drawing::Point(4, 4);
            this->uslugi->Name = L"uslugi";
            this->uslugi->Padding = System::Windows::Forms::Padding(3);
            this->uslugi->Size = System::Drawing::Size(756, 402);
            this->uslugi->TabIndex = 3;
            this->uslugi->Text = L"Us³ugi";
            this->uslugi->UseVisualStyleBackColor = true;
            // 
            // uslugiUsun
            // 
            this->uslugiUsun->BackColor = System::Drawing::Color::Red;
            this->uslugiUsun->Enabled = false;
            this->uslugiUsun->FlatAppearance->BorderSize = 0;
            this->uslugiUsun->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->uslugiUsun->ForeColor = System::Drawing::Color::White;
            this->uslugiUsun->Location = System::Drawing::Point(6, 373);
            this->uslugiUsun->Name = L"uslugiUsun";
            this->uslugiUsun->Size = System::Drawing::Size(141, 23);
            this->uslugiUsun->TabIndex = 7;
            this->uslugiUsun->Text = L"Usuñ";
            this->uslugiUsun->UseVisualStyleBackColor = false;
            this->uslugiUsun->Click += gcnew System::EventHandler(this, &Program::uslugiUsun_Click);
            // 
            // uslugiModyfikuj
            // 
            this->uslugiModyfikuj->BackColor = System::Drawing::Color::Lime;
            this->uslugiModyfikuj->Enabled = false;
            this->uslugiModyfikuj->FlatAppearance->BorderSize = 0;
            this->uslugiModyfikuj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->uslugiModyfikuj->ForeColor = System::Drawing::Color::White;
            this->uslugiModyfikuj->Location = System::Drawing::Point(155, 373);
            this->uslugiModyfikuj->Name = L"uslugiModyfikuj";
            this->uslugiModyfikuj->Size = System::Drawing::Size(141, 23);
            this->uslugiModyfikuj->TabIndex = 6;
            this->uslugiModyfikuj->Text = L"Modyfikuj";
            this->uslugiModyfikuj->UseVisualStyleBackColor = false;
            this->uslugiModyfikuj->Click += gcnew System::EventHandler(this, &Program::uslugiModyfikuj_Click);
            // 
            // uslugiDodaj
            // 
            this->uslugiDodaj->BackColor = System::Drawing::Color::DeepSkyBlue;
            this->uslugiDodaj->FlatAppearance->BorderSize = 0;
            this->uslugiDodaj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->uslugiDodaj->ForeColor = System::Drawing::Color::White;
            this->uslugiDodaj->Location = System::Drawing::Point(304, 373);
            this->uslugiDodaj->Name = L"uslugiDodaj";
            this->uslugiDodaj->Size = System::Drawing::Size(141, 23);
            this->uslugiDodaj->TabIndex = 5;
            this->uslugiDodaj->Text = L"Dodaj";
            this->uslugiDodaj->UseVisualStyleBackColor = false;
            this->uslugiDodaj->Click += gcnew System::EventHandler(this, &Program::uslugiDodaj_Click);
            // 
            // poleUslugi
            // 
            this->poleUslugi->Controls->Add(this->txtUopis);
            this->poleUslugi->Controls->Add(this->txtUczas);
            this->poleUslugi->Controls->Add(this->txtUcena);
            this->poleUslugi->Controls->Add(this->txtUnazwa);
            this->poleUslugi->Controls->Add(this->etykietaOpis);
            this->poleUslugi->Controls->Add(this->etykietaCzas);
            this->poleUslugi->Controls->Add(this->etykietaCena);
            this->poleUslugi->Controls->Add(this->etykietaNazwa);
            this->poleUslugi->Location = System::Drawing::Point(19, 53);
            this->poleUslugi->Name = L"poleUslugi";
            this->poleUslugi->Size = System::Drawing::Size(426, 314);
            this->poleUslugi->TabIndex = 4;
            this->poleUslugi->TabStop = false;
            this->poleUslugi->Text = L"Zabiegi";
            // 
            // txtUopis
            // 
            this->txtUopis->Location = System::Drawing::Point(23, 164);
            this->txtUopis->Multiline = true;
            this->txtUopis->Name = L"txtUopis";
            this->txtUopis->Size = System::Drawing::Size(377, 125);
            this->txtUopis->TabIndex = 8;
            // 
            // txtUczas
            // 
            this->txtUczas->Location = System::Drawing::Point(136, 99);
            this->txtUczas->Name = L"txtUczas";
            this->txtUczas->Size = System::Drawing::Size(62, 20);
            this->txtUczas->TabIndex = 7;
            // 
            // txtUcena
            // 
            this->txtUcena->Location = System::Drawing::Point(124, 63);
            this->txtUcena->Name = L"txtUcena";
            this->txtUcena->Size = System::Drawing::Size(74, 20);
            this->txtUcena->TabIndex = 6;
            // 
            // txtUnazwa
            // 
            this->txtUnazwa->Location = System::Drawing::Point(84, 33);
            this->txtUnazwa->Name = L"txtUnazwa";
            this->txtUnazwa->Size = System::Drawing::Size(114, 20);
            this->txtUnazwa->TabIndex = 5;
            // 
            // etykietaOpis
            // 
            this->etykietaOpis->AutoSize = true;
            this->etykietaOpis->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->etykietaOpis->Location = System::Drawing::Point(20, 136);
            this->etykietaOpis->Name = L"etykietaOpis";
            this->etykietaOpis->Size = System::Drawing::Size(39, 16);
            this->etykietaOpis->TabIndex = 3;
            this->etykietaOpis->Text = L"Opis:";
            // 
            // etykietaCzas
            // 
            this->etykietaCzas->AutoSize = true;
            this->etykietaCzas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->etykietaCzas->Location = System::Drawing::Point(20, 103);
            this->etykietaCzas->Name = L"etykietaCzas";
            this->etykietaCzas->Size = System::Drawing::Size(41, 16);
            this->etykietaCzas->TabIndex = 2;
            this->etykietaCzas->Text = L"Czas:";
            // 
            // etykietaCena
            // 
            this->etykietaCena->AutoSize = true;
            this->etykietaCena->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->etykietaCena->Location = System::Drawing::Point(20, 67);
            this->etykietaCena->Name = L"etykietaCena";
            this->etykietaCena->Size = System::Drawing::Size(43, 16);
            this->etykietaCena->TabIndex = 1;
            this->etykietaCena->Text = L"Cena:";
            // 
            // etykietaNazwa
            // 
            this->etykietaNazwa->AutoSize = true;
            this->etykietaNazwa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->etykietaNazwa->Location = System::Drawing::Point(20, 36);
            this->etykietaNazwa->Name = L"etykietaNazwa";
            this->etykietaNazwa->Size = System::Drawing::Size(52, 16);
            this->etykietaNazwa->TabIndex = 0;
            this->etykietaNazwa->Text = L"Nazwa:";
            // 
            // uslugiSiatka
            // 
            this->uslugiSiatka->AllowUserToAddRows = false;
            this->uslugiSiatka->AllowUserToDeleteRows = false;
            this->uslugiSiatka->AllowUserToOrderColumns = true;
            this->uslugiSiatka->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->uslugiSiatka->BackgroundColor = System::Drawing::Color::White;
            this->uslugiSiatka->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->uslugiSiatka->Location = System::Drawing::Point(451, -4);
            this->uslugiSiatka->Name = L"uslugiSiatka";
            this->uslugiSiatka->ReadOnly = true;
            this->uslugiSiatka->Size = System::Drawing::Size(309, 406);
            this->uslugiSiatka->TabIndex = 3;
            this->uslugiSiatka->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::uslugiSiatka_CellClick);
            // 
            // uslugiSzukaj
            // 
            this->uslugiSzukaj->BackColor = System::Drawing::Color::Orange;
            this->uslugiSzukaj->FlatAppearance->BorderSize = 0;
            this->uslugiSzukaj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->uslugiSzukaj->ForeColor = System::Drawing::Color::White;
            this->uslugiSzukaj->Location = System::Drawing::Point(289, 8);
            this->uslugiSzukaj->Name = L"uslugiSzukaj";
            this->uslugiSzukaj->Size = System::Drawing::Size(96, 23);
            this->uslugiSzukaj->TabIndex = 2;
            this->uslugiSzukaj->Text = L"Szukaj";
            this->uslugiSzukaj->UseVisualStyleBackColor = false;
            this->uslugiSzukaj->Click += gcnew System::EventHandler(this, &Program::uslugiSzukaj_Click);
            // 
            // txtUwyszukaj
            // 
            this->txtUwyszukaj->Location = System::Drawing::Point(84, 10);
            this->txtUwyszukaj->Name = L"txtUwyszukaj";
            this->txtUwyszukaj->Size = System::Drawing::Size(190, 20);
            this->txtUwyszukaj->TabIndex = 1;
            // 
            // etykietaZabieg
            // 
            this->etykietaZabieg->AutoSize = true;
            this->etykietaZabieg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->etykietaZabieg->Location = System::Drawing::Point(24, 11);
            this->etykietaZabieg->Name = L"etykietaZabieg";
            this->etykietaZabieg->Size = System::Drawing::Size(54, 16);
            this->etykietaZabieg->TabIndex = 0;
            this->etykietaZabieg->Text = L"Zabieg:";
            // 
            // pracownik_uslugi
            // 
            this->pracownik_uslugi->Controls->Add(this->txtPUnazwisko);
            this->pracownik_uslugi->Controls->Add(this->txtPUimie);
            this->pracownik_uslugi->Controls->Add(this->etykietaNazwisko);
            this->pracownik_uslugi->Controls->Add(this->etykietaImie);
            this->pracownik_uslugi->Controls->Add(this->etykietaDodajUsluge);
            this->pracownik_uslugi->Controls->Add(this->siatkaDodajUsluge);
            this->pracownik_uslugi->Controls->Add(this->etykietaUslugi);
            this->pracownik_uslugi->Controls->Add(this->siatkaPokazUsluge);
            this->pracownik_uslugi->Controls->Add(this->etykietaPracownicy);
            this->pracownik_uslugi->Controls->Add(this->siatkaPUpracownik);
            this->pracownik_uslugi->Controls->Add(this->pracownik_uslugiSzukaj);
            this->pracownik_uslugi->Controls->Add(this->txtPUszukaj);
            this->pracownik_uslugi->Controls->Add(this->etykietaPracownik);
            this->pracownik_uslugi->Location = System::Drawing::Point(4, 4);
            this->pracownik_uslugi->Name = L"pracownik_uslugi";
            this->pracownik_uslugi->Padding = System::Windows::Forms::Padding(3);
            this->pracownik_uslugi->Size = System::Drawing::Size(756, 402);
            this->pracownik_uslugi->TabIndex = 4;
            this->pracownik_uslugi->Text = L"Pracownik-Us³ugi";
            this->pracownik_uslugi->UseVisualStyleBackColor = true;
            // 
            // txtPUnazwisko
            // 
            this->txtPUnazwisko->Location = System::Drawing::Point(23, 138);
            this->txtPUnazwisko->Name = L"txtPUnazwisko";
            this->txtPUnazwisko->Size = System::Drawing::Size(139, 20);
            this->txtPUnazwisko->TabIndex = 12;
            // 
            // txtPUimie
            // 
            this->txtPUimie->Location = System::Drawing::Point(23, 89);
            this->txtPUimie->Name = L"txtPUimie";
            this->txtPUimie->Size = System::Drawing::Size(139, 20);
            this->txtPUimie->TabIndex = 11;
            // 
            // etykietaNazwisko
            // 
            this->etykietaNazwisko->AutoSize = true;
            this->etykietaNazwisko->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
            this->etykietaNazwisko->Location = System::Drawing::Point(23, 119);
            this->etykietaNazwisko->Name = L"etykietaNazwisko";
            this->etykietaNazwisko->Size = System::Drawing::Size(69, 16);
            this->etykietaNazwisko->TabIndex = 10;
            this->etykietaNazwisko->Text = L"Nazwisko:";
            // 
            // etykietaImie
            // 
            this->etykietaImie->AutoSize = true;
            this->etykietaImie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->etykietaImie->Location = System::Drawing::Point(23, 70);
            this->etykietaImie->Name = L"etykietaImie";
            this->etykietaImie->Size = System::Drawing::Size(36, 16);
            this->etykietaImie->TabIndex = 9;
            this->etykietaImie->Text = L"Imie:";
            // 
            // etykietaDodajUsluge
            // 
            this->etykietaDodajUsluge->AutoSize = true;
            this->etykietaDodajUsluge->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
            this->etykietaDodajUsluge->Location = System::Drawing::Point(6, 204);
            this->etykietaDodajUsluge->Name = L"etykietaDodajUsluge";
            this->etykietaDodajUsluge->Size = System::Drawing::Size(94, 16);
            this->etykietaDodajUsluge->TabIndex = 8;
            this->etykietaDodajUsluge->Text = L"Dodaj us³ugê:";
            // 
            // siatkaDodajUsluge
            // 
            this->siatkaDodajUsluge->AllowUserToAddRows = false;
            this->siatkaDodajUsluge->AllowUserToDeleteRows = false;
            this->siatkaDodajUsluge->AllowUserToOrderColumns = true;
            this->siatkaDodajUsluge->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->siatkaDodajUsluge->BackgroundColor = System::Drawing::Color::White;
            this->siatkaDodajUsluge->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->siatkaDodajUsluge->Location = System::Drawing::Point(6, 234);
            this->siatkaDodajUsluge->Name = L"siatkaDodajUsluge";
            this->siatkaDodajUsluge->ReadOnly = true;
            this->siatkaDodajUsluge->Size = System::Drawing::Size(342, 151);
            this->siatkaDodajUsluge->TabIndex = 7;
            this->siatkaDodajUsluge->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::siatkaDodajUsluge_CellClick);
            // 
            // etykietaUslugi
            // 
            this->etykietaUslugi->AutoSize = true;
            this->etykietaUslugi->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->etykietaUslugi->Location = System::Drawing::Point(368, 204);
            this->etykietaUslugi->Name = L"etykietaUslugi";
            this->etykietaUslugi->Size = System::Drawing::Size(133, 16);
            this->etykietaUslugi->TabIndex = 6;
            this->etykietaUslugi->Text = L"Wykonywane us³ugi:";
            // 
            // siatkaPokazUsluge
            // 
            this->siatkaPokazUsluge->AllowUserToAddRows = false;
            this->siatkaPokazUsluge->AllowUserToDeleteRows = false;
            this->siatkaPokazUsluge->AllowUserToOrderColumns = true;
            this->siatkaPokazUsluge->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->siatkaPokazUsluge->BackgroundColor = System::Drawing::Color::White;
            this->siatkaPokazUsluge->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->siatkaPokazUsluge->Location = System::Drawing::Point(371, 234);
            this->siatkaPokazUsluge->Name = L"siatkaPokazUsluge";
            this->siatkaPokazUsluge->ReadOnly = true;
            this->siatkaPokazUsluge->Size = System::Drawing::Size(385, 151);
            this->siatkaPokazUsluge->TabIndex = 5;
            this->siatkaPokazUsluge->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::siatkaPokazUsluge_CellClick);
            // 
            // etykietaPracownicy
            // 
            this->etykietaPracownicy->AutoSize = true;
            this->etykietaPracownicy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
            this->etykietaPracownicy->Location = System::Drawing::Point(368, 25);
            this->etykietaPracownicy->Name = L"etykietaPracownicy";
            this->etykietaPracownicy->Size = System::Drawing::Size(80, 16);
            this->etykietaPracownicy->TabIndex = 4;
            this->etykietaPracownicy->Text = L"Pracownicy:";
            // 
            // siatkaPUpracownik
            // 
            this->siatkaPUpracownik->AllowUserToAddRows = false;
            this->siatkaPUpracownik->AllowUserToDeleteRows = false;
            this->siatkaPUpracownik->AllowUserToOrderColumns = true;
            this->siatkaPUpracownik->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->siatkaPUpracownik->BackgroundColor = System::Drawing::Color::White;
            this->siatkaPUpracownik->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->siatkaPUpracownik->Location = System::Drawing::Point(371, 54);
            this->siatkaPUpracownik->Name = L"siatkaPUpracownik";
            this->siatkaPUpracownik->ReadOnly = true;
            this->siatkaPUpracownik->Size = System::Drawing::Size(385, 132);
            this->siatkaPUpracownik->TabIndex = 3;
            this->siatkaPUpracownik->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::siatkaPUpracownik_CellClick);
            // 
            // pracownik_uslugiSzukaj
            // 
            this->pracownik_uslugiSzukaj->BackColor = System::Drawing::Color::Orange;
            this->pracownik_uslugiSzukaj->FlatAppearance->BorderSize = 0;
            this->pracownik_uslugiSzukaj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->pracownik_uslugiSzukaj->ForeColor = System::Drawing::Color::White;
            this->pracownik_uslugiSzukaj->Location = System::Drawing::Point(179, 42);
            this->pracownik_uslugiSzukaj->Name = L"pracownik_uslugiSzukaj";
            this->pracownik_uslugiSzukaj->Size = System::Drawing::Size(94, 23);
            this->pracownik_uslugiSzukaj->TabIndex = 2;
            this->pracownik_uslugiSzukaj->Text = L"Szukaj";
            this->pracownik_uslugiSzukaj->UseVisualStyleBackColor = false;
            this->pracownik_uslugiSzukaj->Click += gcnew System::EventHandler(this, &Program::pracownik_uslugiSzukaj_Click);
            // 
            // txtPUszukaj
            // 
            this->txtPUszukaj->Location = System::Drawing::Point(23, 44);
            this->txtPUszukaj->Name = L"txtPUszukaj";
            this->txtPUszukaj->Size = System::Drawing::Size(139, 20);
            this->txtPUszukaj->TabIndex = 1;
            // 
            // etykietaPracownik
            // 
            this->etykietaPracownik->AutoSize = true;
            this->etykietaPracownik->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
            this->etykietaPracownik->Location = System::Drawing::Point(23, 25);
            this->etykietaPracownik->Name = L"etykietaPracownik";
            this->etykietaPracownik->Size = System::Drawing::Size(73, 16);
            this->etykietaPracownik->TabIndex = 0;
            this->etykietaPracownik->Text = L"Pracownik:";
            // 
            // zmiana_hasla
            // 
            this->zmiana_hasla->Controls->Add(this->groupBox1);
            this->zmiana_hasla->Location = System::Drawing::Point(4, 4);
            this->zmiana_hasla->Name = L"zmiana_hasla";
            this->zmiana_hasla->Padding = System::Windows::Forms::Padding(3);
            this->zmiana_hasla->Size = System::Drawing::Size(756, 402);
            this->zmiana_hasla->TabIndex = 2;
            this->zmiana_hasla->Text = L"Zmiana has³a";
            this->zmiana_hasla->UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->pictureBox1);
            this->groupBox1->Controls->Add(this->pb2);
            this->groupBox1->Controls->Add(this->pb1);
            this->groupBox1->Controls->Add(this->txtstarehaslo);
            this->groupBox1->Controls->Add(this->BTzatwierdz);
            this->groupBox1->Controls->Add(this->label1);
            this->groupBox1->Controls->Add(this->txtpowtorzhaslo);
            this->groupBox1->Controls->Add(this->label2);
            this->groupBox1->Controls->Add(this->txtnowehaslo);
            this->groupBox1->Controls->Add(this->label3);
            this->groupBox1->Location = System::Drawing::Point(19, 24);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(656, 338);
            this->groupBox1->TabIndex = 7;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Zmiana has³a";
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(285, 19);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(365, 313);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 11;
            this->pictureBox1->TabStop = false;
            // 
            // pb2
            // 
            this->pb2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb2.Image")));
            this->pb2->Location = System::Drawing::Point(180, 210);
            this->pb2->Name = L"pb2";
            this->pb2->Size = System::Drawing::Size(31, 21);
            this->pb2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
            this->pb2->TabIndex = 10;
            this->pb2->TabStop = false;
            this->pb2->Visible = false;
            // 
            // pb1
            // 
            this->pb1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb1.Image")));
            this->pb1->Location = System::Drawing::Point(180, 141);
            this->pb1->Name = L"pb1";
            this->pb1->Size = System::Drawing::Size(31, 21);
            this->pb1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
            this->pb1->TabIndex = 9;
            this->pb1->TabStop = false;
            this->pb1->Visible = false;
            // 
            // txtstarehaslo
            // 
            this->txtstarehaslo->Location = System::Drawing::Point(28, 85);
            this->txtstarehaslo->Name = L"txtstarehaslo";
            this->txtstarehaslo->PasswordChar = '*';
            this->txtstarehaslo->Size = System::Drawing::Size(149, 20);
            this->txtstarehaslo->TabIndex = 3;
            this->txtstarehaslo->TextChanged += gcnew System::EventHandler(this, &Program::txtstarehaslo_TextChanged);
            // 
            // BTzatwierdz
            // 
            this->BTzatwierdz->BackColor = System::Drawing::Color::DeepSkyBlue;
            this->BTzatwierdz->Enabled = false;
            this->BTzatwierdz->FlatAppearance->BorderSize = 0;
            this->BTzatwierdz->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTzatwierdz->ForeColor = System::Drawing::Color::White;
            this->BTzatwierdz->Location = System::Drawing::Point(28, 250);
            this->BTzatwierdz->Name = L"BTzatwierdz";
            this->BTzatwierdz->Size = System::Drawing::Size(149, 23);
            this->BTzatwierdz->TabIndex = 6;
            this->BTzatwierdz->Text = L"ZatwierdŸ";
            this->BTzatwierdz->UseVisualStyleBackColor = false;
            this->BTzatwierdz->Click += gcnew System::EventHandler(this, &Program::BTzatwierdz_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label1->Location = System::Drawing::Point(25, 64);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(87, 18);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Stare has³o:";
            // 
            // txtpowtorzhaslo
            // 
            this->txtpowtorzhaslo->Location = System::Drawing::Point(28, 210);
            this->txtpowtorzhaslo->Name = L"txtpowtorzhaslo";
            this->txtpowtorzhaslo->PasswordChar = '*';
            this->txtpowtorzhaslo->Size = System::Drawing::Size(149, 20);
            this->txtpowtorzhaslo->TabIndex = 5;
            this->txtpowtorzhaslo->TextChanged += gcnew System::EventHandler(this, &Program::txtpowtorzhaslo_TextChanged);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label2->Location = System::Drawing::Point(25, 116);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(91, 18);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Nowe has³o:";
            // 
            // txtnowehaslo
            // 
            this->txtnowehaslo->Location = System::Drawing::Point(28, 142);
            this->txtnowehaslo->Name = L"txtnowehaslo";
            this->txtnowehaslo->PasswordChar = '*';
            this->txtnowehaslo->Size = System::Drawing::Size(149, 20);
            this->txtnowehaslo->TabIndex = 4;
            this->txtnowehaslo->TextChanged += gcnew System::EventHandler(this, &Program::txtnowehaslo_TextChanged);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label3->Location = System::Drawing::Point(25, 179);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(108, 18);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Powtórz has³o:";
            // 
            // pasekMenu
            // 
            this->pasekMenu->BackColor = System::Drawing::Color::DodgerBlue;
            this->pasekMenu->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->pasekMenu->ImageScalingSize = System::Drawing::Size(60, 60);
            this->pasekMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
                this->menuRezerwacja, this->menuKlienci,
                    this->menuPracownicy, this->menuUslugi, this->menuPraca, this->menuUstawienia
            });
            this->pasekMenu->Location = System::Drawing::Point(0, 0);
            this->pasekMenu->MinimumSize = System::Drawing::Size(0, 80);
            this->pasekMenu->Name = L"pasekMenu";
            this->pasekMenu->Size = System::Drawing::Size(817, 80);
            this->pasekMenu->TabIndex = 1;
            this->pasekMenu->Text = L"toolStrip1";
            // 
            // menuRezerwacja
            // 
            this->menuRezerwacja->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->menuRezerwacja->ForeColor = System::Drawing::Color::White;
            this->menuRezerwacja->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuRezerwacja.Image")));
            this->menuRezerwacja->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->menuRezerwacja->Margin = System::Windows::Forms::Padding(44, 1, 0, 2);
            this->menuRezerwacja->Name = L"menuRezerwacja";
            this->menuRezerwacja->Size = System::Drawing::Size(87, 77);
            this->menuRezerwacja->Text = L"Rezerwacja";
            this->menuRezerwacja->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
            this->menuRezerwacja->Click += gcnew System::EventHandler(this, &Program::menuRezerwacja_Click);
            // 
            // menuKlienci
            // 
            this->menuKlienci->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->menuKlienci->ForeColor = System::Drawing::Color::White;
            this->menuKlienci->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuKlienci.Image")));
            this->menuKlienci->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->menuKlienci->Margin = System::Windows::Forms::Padding(44, 1, 0, 2);
            this->menuKlienci->Name = L"menuKlienci";
            this->menuKlienci->Size = System::Drawing::Size(64, 77);
            this->menuKlienci->Text = L"Klienci";
            this->menuKlienci->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
            this->menuKlienci->Click += gcnew System::EventHandler(this, &Program::menuKlienci_Click);
            // 
            // menuPracownicy
            // 
            this->menuPracownicy->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->menuPracownicy->ForeColor = System::Drawing::Color::White;
            this->menuPracownicy->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuPracownicy.Image")));
            this->menuPracownicy->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->menuPracownicy->Margin = System::Windows::Forms::Padding(44, 1, 0, 2);
            this->menuPracownicy->Name = L"menuPracownicy";
            this->menuPracownicy->Size = System::Drawing::Size(86, 77);
            this->menuPracownicy->Text = L"Pracownicy";
            this->menuPracownicy->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
            this->menuPracownicy->Click += gcnew System::EventHandler(this, &Program::menuPracownicy_Click);
            // 
            // menuUslugi
            // 
            this->menuUslugi->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->menuUslugi->ForeColor = System::Drawing::Color::White;
            this->menuUslugi->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuUslugi.Image")));
            this->menuUslugi->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->menuUslugi->Margin = System::Windows::Forms::Padding(44, 1, 0, 2);
            this->menuUslugi->Name = L"menuUslugi";
            this->menuUslugi->Size = System::Drawing::Size(64, 77);
            this->menuUslugi->Text = L"Us³ugi";
            this->menuUslugi->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
            this->menuUslugi->Click += gcnew System::EventHandler(this, &Program::menuUslugi_Click);
            // 
            // menuPraca
            // 
            this->menuPraca->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->menuPraca->ForeColor = System::Drawing::Color::White;
            this->menuPraca->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuPraca.Image")));
            this->menuPraca->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->menuPraca->Margin = System::Windows::Forms::Padding(44, 1, 0, 2);
            this->menuPraca->Name = L"menuPraca";
            this->menuPraca->Size = System::Drawing::Size(64, 77);
            this->menuPraca->Text = L"Praca";
            this->menuPraca->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
            this->menuPraca->Click += gcnew System::EventHandler(this, &Program::menuPraca_Click);
            // 
            // menuUstawienia
            // 
            this->menuUstawienia->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->menuUstawienia->ForeColor = System::Drawing::Color::White;
            this->menuUstawienia->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuUstawienia.Image")));
            this->menuUstawienia->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->menuUstawienia->Margin = System::Windows::Forms::Padding(47, 1, 0, 2);
            this->menuUstawienia->Name = L"menuUstawienia";
            this->menuUstawienia->Size = System::Drawing::Size(82, 77);
            this->menuUstawienia->Text = L"Ustawienia";
            this->menuUstawienia->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
            this->menuUstawienia->Click += gcnew System::EventHandler(this, &Program::menuUstawienia_Click);
            // 
            // Program
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::DodgerBlue;
            this->ClientSize = System::Drawing::Size(817, 536);
            this->Controls->Add(this->pasekMenu);
            this->Controls->Add(this->kontrola);
            this->Name = L"Program";
            this->Text = L"Us³ugi";
            this->kontrola->ResumeLayout(false);
            this->rezerwacja->ResumeLayout(false);
            this->rezerwacja->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->siatkaRpracownik))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->siatkaRklient))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->siatkaRuslugi))->EndInit();
            this->klienci->ResumeLayout(false);
            this->klienci->PerformLayout();
            this->daneKlienta->ResumeLayout(false);
            this->daneKlienta->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->siatkaKklient))->EndInit();
            this->pracownicy->ResumeLayout(false);
            this->pracownicy->PerformLayout();
            this->godzinyPracy->ResumeLayout(false);
            this->godzinyPracy->PerformLayout();
            this->szablonyGodzin->ResumeLayout(false);
            this->danePracownika->ResumeLayout(false);
            this->danePracownika->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pracownicySiatka))->EndInit();
            this->uslugi->ResumeLayout(false);
            this->uslugi->PerformLayout();
            this->poleUslugi->ResumeLayout(false);
            this->poleUslugi->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->uslugiSiatka))->EndInit();
            this->pracownik_uslugi->ResumeLayout(false);
            this->pracownik_uslugi->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->siatkaDodajUsluge))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->siatkaPokazUsluge))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->siatkaPUpracownik))->EndInit();
            this->zmiana_hasla->ResumeLayout(false);
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1))->EndInit();
            this->pasekMenu->ResumeLayout(false);
            this->pasekMenu->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: void zmianaHasla();

    private: void czyToPracownik();

    private: System::Void txtstarehaslo_TextChanged(System::Object^  sender, System::EventArgs^  e);

    private: System::Void txtnowehaslo_TextChanged(System::Object^  sender, System::EventArgs^  e);

    private: System::Void txtpowtorzhaslo_TextChanged(System::Object^  sender, System::EventArgs^  e);

    private: System::Void BTzatwierdz_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void pokazUzytkownika(System::Windows::Forms::TextBox^ pole, System::Windows::Forms::DataGridView^ siatka);

    private: System::Void pracownicySzukaj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void pracownicySiatka_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);

    private: System::Void pracownicyDodaj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void pracownicyModyfikuj_Click(System::Object^  sender, System::EventArgs^  e);

    private: void wyczysc(Control^kontener);

    private: System::Void pracownicyUsun_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void cbPpracownik_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

    private: void czas_pracy(int czas);

    private: System::Void czas7_15_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void czas8_16_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void czas9_17_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void czas10_18_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void cbPszablony_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

    private: Void pokaz_us³ugi(System::Windows::Forms::TextBox^ pole, System::Windows::Forms::DataGridView^ siatka);

    private: System::Void uslugiSzukaj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void uslugiDodaj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void uslugiSiatka_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);

    private: System::Void uslugiModyfikuj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void uslugiUsun_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void pracownik_uslugiSzukaj_Click(System::Object^  sender, System::EventArgs^  e);

    private: void pokaz_uslugi_pracownika();

    private: System::Void siatkaPUpracownik_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);

    private: System::Void siatkaDodajUsluge_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);

    private: System::Void siatkaPokazUsluge_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);

    private: Void pokazKklienta(System::Windows::Forms::TextBox^ pole, System::Windows::Forms::DataGridView^ siatka);

    private: System::Void klientSzukaj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void siatkaKklient_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);

    private: System::Void klientDodaj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void klientModyfikuj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void klientUsun_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void rezerwacjaUszukaj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void rezerwacjaKszukaj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void rezerwacjaPszukaj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void siatkaRuslugi_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);

    private: System::Void siatkaRklient_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);

    private: System::Void siatkaRpracownik_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);

    private: void pokaz_terminy();

    private: Void Pole_klik(System::Object^  sender, System::EventArgs^  e);

    private: System::Void kalendarz_DateSelected(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e);

    private: System::Void rezerwacjaDodaj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void rezerwacjaModyfikuj_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void rezerwacjaUsun_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void menuRezerwacja_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void menuKlienci_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void menuPraca_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void menuUslugi_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void menuPracownicy_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void menuUstawienia_Click(System::Object^  sender, System::EventArgs^  e);
    };
}
