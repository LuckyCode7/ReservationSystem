#include "Logowanie.h"

System::Void Gabinet::Logowanie::logowanieAnuluj_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->Close();
}

System::Void Gabinet::Logowanie::logowanieZaloguj_Click(System::Object^  sender, System::EventArgs^  e)
{
    String^ konfiguracja = L"datasource = localhost; port = 3306; username = root; password = ***; database = gabinet";
    MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
    MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT uzytkownik_id FROM uzytkownik WHERE uzytkownik_nazwa = '" + this->txtuzytkownik->Text + "' AND has³o = PASSWORD('" + this->txthaslo->Text + "');", laczBaze);
    MySqlDataReader^ odczytanie;
    try
    {
        laczBaze->Open();
        odczytanie = zapytanie->ExecuteReader();
        if (odczytanie->Read())
        {
            int id_uzytkownika = odczytanie->GetInt32(0);
            this->Hide();
            Program^ program = gcnew Program(id_uzytkownika);
            program->ShowDialog();
            this->Close();
        }
        else
        {
            MessageBox::Show("Niepoprawna nazwa u¿ytkownika lub has³o", "B³¹d logowania", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show(ex->Message);
    }
    laczBaze->Close();
}

System::Void Gabinet::Logowanie::txtuzytkownik_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->txtuzytkownik->Text = "";
}

System::Void Gabinet::Logowanie::txthaslo_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->txthaslo->Text = "";
    this->txthaslo->PasswordChar = '*';
}