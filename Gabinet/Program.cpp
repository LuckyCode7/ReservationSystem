#include "Program.h"

namespace zmienne
{
    int id_rekordu;
    int pracownik_typ;
    int id_usluga;
    int id_klient;
    int id_pracownik;
    int id_wizyty;
}

void Gabinet::Program::zmianaHasla()
{
    if (txtstarehaslo->Text != "" && txtnowehaslo->Text != "" && txtpowtorzhaslo->Text == txtnowehaslo->Text)
    {
        this->BTzatwierdz->Enabled = true;
        this->pb1->Visible = true;
        this->pb2->Visible = true;
    }
    else
    {
        this->BTzatwierdz->Enabled = false;
        this->pb1->Visible = false;
        this->pb2->Visible = false;
    }
}

System::Void Gabinet::Program::txtstarehaslo_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
    this->zmianaHasla();
}

System::Void Gabinet::Program::txtnowehaslo_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
    this->zmianaHasla();
}

System::Void Gabinet::Program::txtpowtorzhaslo_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
    this->zmianaHasla();
}

System::Void Gabinet::Program::BTzatwierdz_Click(System::Object^  sender, System::EventArgs^  e)
{
    MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
    MySqlCommand^ zapytanie = gcnew MySqlCommand("UPDATE uzytkownik SET has³o = password('" + this->txtnowehaslo->Text +
        "') WHERE uzytkownik_id = " + this->id_uzytkownika + " AND has³o = password('" + this->txtstarehaslo->Text + "');", laczBaze);
    try
    {
        laczBaze->Open();

        if (zapytanie->ExecuteNonQuery())
        {
            MessageBox::Show("Nast¹pi³a zmiana has³a", "Has³o", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else
        {
            MessageBox::Show("Podane has³o jest niepoprawne");
        }
        laczBaze->Close();
    }
    catch (Exception^ komunikat)
    {
        MessageBox::Show(komunikat->Message);
    }
}

System::Void Gabinet::Program::pokazUzytkownika(System::Windows::Forms::TextBox^ pole, System::Windows::Forms::DataGridView^ siatka)
{
    MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
    MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT uzytkownik_id, imie AS Imie, nazwisko AS Nazwisko, uzytkownik_nazwa AS Login, pracownik AS Pracownik FROM uzytkownik WHERE CONCAT(imie, ' ', nazwisko, ' ', uzytkownik_nazwa) LIKE ('%" + pole->Text + "%') ORDER BY nazwisko;", laczBaze);
    try
    {
        laczBaze->Open();
        MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
        moja->SelectCommand = zapytanie;
        DataTable^ tabela = gcnew DataTable();
        moja->Fill(tabela);

        BindingSource^ zrodlo = gcnew BindingSource();
        zrodlo->DataSource = tabela;
        siatka->DataSource = zrodlo;
        laczBaze->Close();
    }
    catch (Exception^ komunikat)
    {
        MessageBox::Show(komunikat->Message);
    }
    siatka->Columns[0]->Visible = false;
}

System::Void Gabinet::Program::pracownicySzukaj_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->pokazUzytkownika(this->txtPszukaj, this->pracownicySiatka);
}

System::Void Gabinet::Program::pracownicySiatka_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
{
    if (e->RowIndex >= 0)
    {
        zmienne::id_rekordu = Convert::ToInt32(this->pracownicySiatka->Rows[e->RowIndex]->Cells[0]->Value);
        this->txtPimie->Text = this->pracownicySiatka->Rows[e->RowIndex]->Cells[1]->Value->ToString();
        this->txtPnazwisko->Text = this->pracownicySiatka->Rows[e->RowIndex]->Cells["nazwisko"]->Value->ToString();
        this->txtPlogin->Text = this->pracownicySiatka->Rows[e->RowIndex]->Cells["login"]->Value->ToString();
        this->cbPpracownik->Checked = Convert::ToBoolean(this->pracownicySiatka->Rows[e->RowIndex]->Cells["pracownik"]->Value);
        this->pracownicyUsun->Enabled = true;
        this->pracownicyModyfikuj->Enabled = true;
        if (this->cbPpracownik->Checked)
        {
            MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
            MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM godziny WHERE uzytkownik_id = " + zmienne::id_rekordu + ";", laczBaze);
            MySqlDataReader^ dane;
            try
            {
                laczBaze->Open();
                dane = zapytanie->ExecuteReader();
                while (dane->Read())
                {
                    this->txtPponp->Text = dane->GetString("pon_od");
                    this->txtPponk->Text = dane->GetString("pon_do");
                    this->txtPwtp->Text = dane->GetString("wt_od");
                    this->txtPwtk->Text = dane->GetString("wt_do");
                    this->txtPsrp->Text = dane->GetString("œr_od");
                    this->txtPsrk->Text = dane->GetString("œr_do");
                    this->txtPczwp->Text = dane->GetString("czw_od");
                    this->txtPczwk->Text = dane->GetString("czw_do");
                    this->txtPptp->Text = dane->GetString("pt_od");
                    this->txtPptk->Text = dane->GetString("pt_do");
                    this->txtPsobp->Text = dane->GetString("sob_od");
                    this->txtPsobk->Text = dane->GetString("sob_do");
                }
                laczBaze->Close();
            }
            catch (Exception^ komunikat)
            {
                MessageBox::Show(komunikat->Message);
            }
        }
    }
}

void Gabinet::Program::czyToPracownik()
{
    if (this->cbPpracownik->Checked)
    {
        zmienne::pracownik_typ = 1;
    }
    else
    {
        zmienne::pracownik_typ = 0;
    }
}

System::Void Gabinet::Program::pracownicyDodaj_Click(System::Object^  sender, System::EventArgs^  e)
{
    if (this->txtPimie->Text->Length < 3 || this->txtPnazwisko->Text->Length <= 3 || this->txtPlogin->Text->Length < 4)
    {
        MessageBox::Show("WprowadŸ poprawne dane ! ", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    else
    {
        this->czyToPracownik();
        MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
        MySqlCommand^ polecenie = laczBaze->CreateCommand();
        MySqlTransaction^ transakcja;
        laczBaze->Open();
        transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
        polecenie->Connection = laczBaze;
        polecenie->Transaction = transakcja;
        try
        {
            polecenie->CommandText = "INSERT INTO uzytkownik SET uzytkownik_nazwa = '" + this->txtPlogin->Text +
                "', imie = '" + this->txtPimie->Text + "', nazwisko = '" + this->txtPnazwisko->Text + "', has³o = PASSWORD('" + this->txtPlogin->Text +
                "'), pracownik = " + zmienne::pracownik_typ + ";";
            polecenie->ExecuteNonQuery();
            if (this->cbPpracownik->Checked)
            {
                polecenie->CommandText = "INSERT INTO godziny SET uzytkownik_id = last_insert_id(), pon_od = '" + this->txtPponp->Text +
                    "', pon_do = '" + this->txtPponk->Text + "', wt_od = '" + this->txtPwtp->Text + "', wt_do = '" + this->txtPwtk->Text +
                    "', œr_od = '" + this->txtPsrp->Text + "', œr_do = '" + this->txtPsrk->Text + "', czw_od = '" + this->txtPczwp->Text +
                    "', czw_do = '" + this->txtPczwk->Text + "',pt_od = '" + this->txtPptp->Text + "', pt_do = '" + this->txtPptk->Text +
                    "', sob_od = '" + this->txtPsobp->Text + "', sob_do = '" + this->txtPsobk->Text + "';";
                polecenie->ExecuteNonQuery();
            }
            transakcja->Commit();
            MessageBox::Show("Wprpwadzono nowego u¿ytkownika: " + this->txtPimie->Text + " " " " + this->txtPnazwisko->Text + "", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ komunikat)
        {
            MessageBox::Show(komunikat->Message);
            transakcja->Rollback();
        }
        this->pokazUzytkownika(this->txtPUszukaj, this->pracownicySiatka);
        laczBaze->Close();
    }
}

System::Void Gabinet::Program::pracownicyModyfikuj_Click(System::Object^  sender, System::EventArgs^  e)
{
    if (this->txtPimie->Text->Length < 3 || this->txtPnazwisko->Text->Length <= 3 || this->txtPlogin->Text->Length < 4)
    {
        MessageBox::Show("WprowadŸ poprawne dane ! ", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    else
    {
        this->czyToPracownik();
        MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
        MySqlCommand^ polecenie = laczBaze->CreateCommand();
        MySqlTransaction^ transakcja;
        laczBaze->Open();
        transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
        polecenie->Connection = laczBaze;
        polecenie->Transaction = transakcja;
        try
        {
            polecenie->CommandText = "SELECT * FROM godziny WHERE uzytkownik_id = " + zmienne::id_rekordu + ";";
            MySqlDataReader^ wynik = polecenie->ExecuteReader();
            bool rezultat = wynik->HasRows;
            wynik->Close();
            polecenie->CommandText = "UPDATE uzytkownik SET uzytkownik_nazwa = '" + this->txtPlogin->Text +
                "', imie = '" + this->txtPimie->Text + "', nazwisko = '" + this->txtPnazwisko->Text + "', pracownik = " + zmienne::pracownik_typ +
                " WHERE uzytkownik_id = " + zmienne::id_rekordu + ";";
            polecenie->ExecuteNonQuery();
            if (rezultat == true && this->cbPpracownik->Checked == true)
            {
                polecenie->CommandText = "UPDATE godziny SET pon_od = '" + this->txtPponp->Text +
                    "', pon_do = '" + this->txtPponk->Text + "', wt_od = '" + this->txtPwtp->Text + "', wt_do = '" + this->txtPwtk->Text +
                    "', œr_od = '" + this->txtPsrp->Text + "', œr_do = '" + this->txtPsrk->Text + "', czw_od = '" + this->txtPczwp->Text +
                    "', czw_do = '" + this->txtPczwk->Text + "',pt_od = '" + this->txtPptp->Text + "', pt_do = '" + this->txtPptk->Text +
                    "', sob_od = '" + this->txtPsobp->Text + "', sob_do = '" + this->txtPsobk->Text + "' WHERE uzytkownik_id = " + zmienne::id_rekordu + ";";
                polecenie->ExecuteNonQuery();
            }
            else if (rezultat == false && this->cbPpracownik->Checked)
            {
                polecenie->CommandText = "INSERT INTO godziny SET uzytkownik_id = " + zmienne::id_rekordu + ", pon_od = '" + this->txtPponp->Text +
                    "', pon_do = '" + this->txtPponk->Text + "', wt_od = '" + this->txtPwtp->Text + "', wt_do = '" + this->txtPwtk->Text +
                    "', œr_od = '" + this->txtPsrp->Text + "', œr_do = '" + this->txtPsrk->Text + "', czw_od = '" + this->txtPczwp->Text +
                    "', czw_do = '" + this->txtPczwk->Text + "',pt_od = '" + this->txtPptp->Text + "', pt_do = '" + this->txtPptk->Text +
                    "', sob_od = '" + this->txtPsobp->Text + "', sob_do = '" + this->txtPsobk->Text + "';";
                polecenie->ExecuteNonQuery();
            }
            transakcja->Commit();
            MessageBox::Show("Zmodyfikowano dane u¿ytkownika: " + this->txtPimie->Text + " " " " + this->txtPnazwisko->Text + "", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ komunikat)
        {
            MessageBox::Show(komunikat->Message);
            transakcja->Rollback();
        }
        pokazUzytkownika(this->txtPUszukaj, this->pracownicySiatka);
        laczBaze->Close();
    }
}

void Gabinet::Program::wyczysc(Control^kontener)
{
    for each (Control^ element in kontener->Controls)
    {
        if (element->GetType() == TextBox::typeid || element->GetType() == MaskedTextBox::typeid)
        {
            element->Text = "";
        }
    }
}

System::Void Gabinet::Program::pracownicyUsun_Click(System::Object^  sender, System::EventArgs^  e)
{
    if (zmienne::id_rekordu == 1)
    {
        MessageBox::Show("Nie mo¿na usun¹æ administratora ! ", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    else
    {
        this->czyToPracownik();
        MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
        MySqlCommand^ polecenie = laczBaze->CreateCommand();
        MySqlTransaction^ transakcja;
        laczBaze->Open();
        transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
        polecenie->Connection = laczBaze;
        polecenie->Transaction = transakcja;
        try
        {
            if (MessageBox::Show("Czy na pewno usun¹æ wybranego u¿ytkownika ?", "Ostrze¿enie", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                polecenie->CommandText = "DELETE FROM wizyty WHERE uzytkownik_id = " + zmienne::id_rekordu + ";";
                polecenie->ExecuteNonQuery();
                polecenie->CommandText = "DELETE FROM uzytkownik_uslugi WHERE uzytkownik_id = " + zmienne::id_rekordu + ";";
                polecenie->ExecuteNonQuery();
                polecenie->CommandText = "DELETE FROM godziny WHERE uzytkownik_id = " + zmienne::id_rekordu + ";";
                polecenie->ExecuteNonQuery();
                polecenie->CommandText = "DELETE FROM uzytkownik WHERE uzytkownik_id = " + zmienne::id_rekordu + ";";
                polecenie->ExecuteNonQuery();
                transakcja->Commit();
                MessageBox::Show("Usuniêto u¿tkownika: " + this->txtPimie->Text + " " " " + this->txtPnazwisko->Text + " ", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }
        catch (Exception^ komunikat)
        {
            MessageBox::Show(komunikat->Message);
            transakcja->Rollback();
        }
        pokazUzytkownika(this->txtPUszukaj, this->pracownicySiatka);
        laczBaze->Close();
    }
    wyczysc(this->danePracownika);
    wyczysc(this->godzinyPracy);
    this->cbPpracownik->Checked = false;
}

System::Void Gabinet::Program::cbPpracownik_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
    if (this->cbPpracownik->Checked)
    {
        this->godzinyPracy->Visible = true;
        this->wyczysc(this->godzinyPracy);
    }
    else
    {
        this->godzinyPracy->Visible = false;
    }
}

void Gabinet::Program::czas_pracy(int czas)
{
    array <TextBox^> ^start_pracy = { txtPponp, txtPwtp, txtPsrp, txtPczwp, txtPptp, txtPsobp };
    array <TextBox^> ^koniec_pracy = { txtPponk, txtPwtk, txtPsrk, txtPczwk, txtPptk, txtPsobk };

    for (int i = 0; i <= 5; i++)
    {
        start_pracy[i]->Text = czas + ":00";
        koniec_pracy[i]->Text = czas + 8 + ":00";
    }
}

System::Void Gabinet::Program::czas7_15_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->czas_pracy(7);
}

System::Void Gabinet::Program::czas8_16_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->czas_pracy(8);
}

System::Void Gabinet::Program::czas9_17_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->czas_pracy(9);
}

System::Void Gabinet::Program::czas10_18_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->czas_pracy(10);
}

System::Void Gabinet::Program::cbPszablony_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
    if (this->cbPszablony->Checked)
    {
        this->szablonyGodzin->Visible = true;
    }
    else
    {
        this->szablonyGodzin->Visible = false;
    }
}

System::Void Gabinet::Program::pokaz_us³ugi(System::Windows::Forms::TextBox^ pole, System::Windows::Forms::DataGridView^ siatka)
{
    MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
    MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM uslugi WHERE nazwa LIKE ('%" + pole->Text + "%') ORDER BY nazwa;", laczBaze);
    try
    {
        laczBaze->Open();
        MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
        moja->SelectCommand = zapytanie;
        DataTable^ tabela = gcnew DataTable();
        moja->Fill(tabela);
        BindingSource^ zrodlo = gcnew BindingSource();
        zrodlo->DataSource = tabela;
        siatka->DataSource = zrodlo;
        laczBaze->Close();
    }
    catch (Exception^ komunikat)
    {
        MessageBox::Show(komunikat->Message);
    }
    siatka->Columns[0]->Visible = false;
}

System::Void Gabinet::Program::uslugiSzukaj_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->pokaz_us³ugi(this->txtUwyszukaj, this->uslugiSiatka);
}

System::Void Gabinet::Program::uslugiDodaj_Click(System::Object^  sender, System::EventArgs^  e)
{
    if (this->txtUnazwa->Text->Length < 3 || this->txtUcena->Text->Length < 1 || this->txtUczas->Text->Length < 5)
    {
        MessageBox::Show("WprowadŸ poprawne dane ! ", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    else
    {
        this->czyToPracownik();
        MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
        MySqlCommand^ polecenie = laczBaze->CreateCommand();
        MySqlTransaction^ transakcja;
        laczBaze->Open();
        transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
        polecenie->Connection = laczBaze;
        polecenie->Transaction = transakcja;
        try
        {
            String^ cena = this->txtUcena->Text->Replace(",", ".");
            polecenie->CommandText = "INSERT INTO uslugi SET nazwa = '" + this->txtUnazwa->Text +
                "', cena = '" + cena + "', czas = '" + this->txtUczas->Text + "', opis = '" + this->txtUopis->Text +
                "'; ";
            polecenie->ExecuteNonQuery();
            transakcja->Commit();
            MessageBox::Show("Wprpwadzono now¹ us³ugê: " + txtUnazwa->Text + "", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ komunikat)
        {
            MessageBox::Show(komunikat->Message);
            transakcja->Rollback();
        }
        this->pokaz_us³ugi(this->txtUwyszukaj, uslugiSiatka);
        laczBaze->Close();
    }
}

System::Void Gabinet::Program::uslugiSiatka_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
{
    if (e->RowIndex >= 0)
    {
        zmienne::id_rekordu = Convert::ToInt32(this->uslugiSiatka->Rows[e->RowIndex]->Cells[0]->Value);
        this->txtUnazwa->Text = this->uslugiSiatka->Rows[e->RowIndex]->Cells[1]->Value->ToString();
        this->txtUcena->Text = this->uslugiSiatka->Rows[e->RowIndex]->Cells["cena"]->Value->ToString();
        this->txtUczas->Text = this->uslugiSiatka->Rows[e->RowIndex]->Cells["czas"]->Value->ToString();
        this->txtUopis->Text = this->uslugiSiatka->Rows[e->RowIndex]->Cells["opis"]->Value->ToString();
        this->uslugiModyfikuj->Enabled = true;
        this->uslugiUsun->Enabled = true;
    }
}

System::Void Gabinet::Program::uslugiModyfikuj_Click(System::Object^  sender, System::EventArgs^  e)
{
    if (this->txtUnazwa->Text->Length < 3 || this->txtUcena->Text->Length < 1 || this->txtUczas->Text->Length < 5)
    {
        MessageBox::Show("WprowadŸ poprawne dane ! ", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    else
    {
        this->czyToPracownik();
        MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
        MySqlCommand^ polecenie = laczBaze->CreateCommand();
        MySqlTransaction^ transakcja;
        laczBaze->Open();
        transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
        polecenie->Connection = laczBaze;
        polecenie->Transaction = transakcja;
        try
        {
            String^ cena = this->txtUcena->Text->Replace(",", ".");
            polecenie->CommandText = "UPDATE uslugi SET nazwa = '" + this->txtUnazwa->Text +
                "', cena = '" + cena + "', czas = '" + this->txtUczas->Text + "', opis = '" + this->txtUopis->Text +
                "' WHERE uslugi_id = " + zmienne::id_rekordu + "; ";
            polecenie->ExecuteNonQuery();
            transakcja->Commit();
            MessageBox::Show("Zmodyfikowano us³ugê: " + this->txtUnazwa->Text + "", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ komunikat)
        {
            MessageBox::Show(komunikat->Message);
            transakcja->Rollback();
        }
        pokaz_us³ugi(this->txtUwyszukaj, this->uslugiSiatka);
        laczBaze->Close();
    }
}

System::Void Gabinet::Program::uslugiUsun_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->czyToPracownik();
    MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
    MySqlCommand^ polecenie = laczBaze->CreateCommand();
    MySqlTransaction^ transakcja;
    laczBaze->Open();
    transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
    polecenie->Connection = laczBaze;
    polecenie->Transaction = transakcja;
    try
    {
        if (MessageBox::Show("Czy na pewno usun¹æ wybran¹ us³ugê ?", "Ostrze¿enie", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
        {
            polecenie->CommandText = "DELETE FROM wizyty WHERE uslugi_id = " + zmienne::id_rekordu + ";";
            polecenie->ExecuteNonQuery();
            polecenie->CommandText = "DELETE FROM uzytkownik_uslugi WHERE uslugi_id = " + zmienne::id_rekordu + ";";
            polecenie->ExecuteNonQuery();
            polecenie->CommandText = "DELETE FROM uslugi WHERE uslugi_id = " + zmienne::id_rekordu + ";";
            polecenie->ExecuteNonQuery();
            transakcja->Commit();
            MessageBox::Show("Usuniêto us³ugê: " + this->txtUnazwa->Text + " ", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    }
    catch (Exception^ komunikat)
    {
        MessageBox::Show(komunikat->Message);
        transakcja->Rollback();
    }
    this->pokaz_us³ugi(this->txtUwyszukaj, this->uslugiSiatka);
    laczBaze->Close();
    this->wyczysc(this->poleUslugi);
}

System::Void Gabinet::Program::pracownik_uslugiSzukaj_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->pokazUzytkownika(this->txtPUszukaj, this->siatkaPUpracownik);
}

void Gabinet::Program::pokaz_uslugi_pracownika()
{
    MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
    MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT uslugi.uslugi_id, uslugi.nazwa, uslugi.cena, uslugi.czas FROM uslugi, uzytkownik_uslugi WHERE uslugi.uslugi_id = uzytkownik_uslugi.uslugi_id AND uzytkownik_uslugi.uzytkownik_id = " + zmienne::id_rekordu + " ORDER BY nazwa;", laczBaze);
    try
    {
        laczBaze->Open();
        MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
        moja->SelectCommand = zapytanie;
        DataTable^ tabela = gcnew DataTable();
        moja->Fill(tabela);
        BindingSource^ zrodlo = gcnew BindingSource();
        zrodlo->DataSource = tabela;
        this->siatkaPokazUsluge->DataSource = zrodlo;
        laczBaze->Close();
    }
    catch (Exception^ komunikat)
    {
        MessageBox::Show(komunikat->Message);
    }
    this->siatkaPokazUsluge->Columns[0]->Visible = false;
}

System::Void Gabinet::Program::siatkaPUpracownik_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
{
    if (e->RowIndex >= 0)
    {
        zmienne::id_rekordu = Convert::ToInt32(this->siatkaPUpracownik->Rows[e->RowIndex]->Cells[0]->Value);
        this->txtPUimie->Text = this->siatkaPUpracownik->Rows[e->RowIndex]->Cells["imie"]->Value->ToString();
        this->txtPUnazwisko->Text = this->siatkaPUpracownik->Rows[e->RowIndex]->Cells["nazwisko"]->Value->ToString();
        this->pokaz_uslugi_pracownika();
        MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
        MySqlCommand^zapytanie = gcnew MySqlCommand("SELECT * FROM uslugi;", laczBaze);

        try
        {
            laczBaze->Open();
            MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
            moja->SelectCommand = zapytanie;
            DataTable^ tabela = gcnew DataTable();
            moja->Fill(tabela);
            BindingSource^ zrodlo = gcnew BindingSource();
            zrodlo->DataSource = tabela;
            this->siatkaDodajUsluge->DataSource = zrodlo;
            laczBaze->Close();
        }
        catch (Exception^ komunikat)
        {
            MessageBox::Show(komunikat->Message);
        }
        this->siatkaDodajUsluge->Columns[0]->Visible = false;
    }
}

System::Void Gabinet::Program::siatkaDodajUsluge_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
{
    if (e->RowIndex >= 0)
    {
        zmienne::id_usluga = Convert::ToInt32(this->siatkaDodajUsluge->Rows[e->RowIndex]->Cells[0]->Value);
        if (MessageBox::Show("Czy dodaæ now¹ us³ugê do pracownika ?", "Dodawanie us³ug", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
        {
            MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
            MySqlCommand^ polecenie = laczBaze->CreateCommand();
            MySqlTransaction^ transakcja;
            laczBaze->Open();
            transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
            polecenie->Connection = laczBaze;
            polecenie->Transaction = transakcja;
            try
            {
                polecenie->CommandText = "INSERT INTO uzytkownik_uslugi SET uzytkownik_id = " + zmienne::id_rekordu +
                    ", uslugi_id = " + zmienne::id_usluga + " ; ";
                polecenie->ExecuteNonQuery();
                transakcja->Commit();
                MessageBox::Show("Wprpwadzono now¹ us³ugê dla wybranego pracownika", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (Exception^ komunikat)
            {
                MessageBox::Show(komunikat->Message);
                transakcja->Rollback();
            }
            this->pokaz_uslugi_pracownika();
            laczBaze->Close();
        }
    }
}

System::Void Gabinet::Program::siatkaPokazUsluge_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
{
    if (e->RowIndex >= 0)
    {
        zmienne::id_usluga = Convert::ToInt32(this->siatkaPokazUsluge->Rows[e->RowIndex]->Cells[0]->Value);
        if (MessageBox::Show("Czy na pewno usun¹æ dan¹ us³ugê pracownika ?", "Usuwanie us³ug", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
        {
            MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
            MySqlCommand^ polecenie = laczBaze->CreateCommand();
            MySqlTransaction^ transakcja;
            laczBaze->Open();
            transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
            polecenie->Connection = laczBaze;
            polecenie->Transaction = transakcja;
            try
            {
                polecenie->CommandText = "DELETE FROM uzytkownik_uslugi WHERE uzytkownik_id = " + zmienne::id_rekordu +
                    " AND uslugi_id = " + zmienne::id_usluga + " ; ";
                polecenie->ExecuteNonQuery();
                transakcja->Commit();
                MessageBox::Show("Usuniêto us³ugê pracownika", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (Exception^ komunikat)
            {
                MessageBox::Show(komunikat->Message);
                transakcja->Rollback();
            }
            this->pokaz_uslugi_pracownika();
            laczBaze->Close();
        }
    }
}

System::Void Gabinet::Program::pokazKklienta(System::Windows::Forms::TextBox^ pole, System::Windows::Forms::DataGridView^ siatka)
{
    MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
    MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM klient WHERE CONCAT(imie, ' ',nazwisko,' ',ulica,' ',kod_pocztowy,' ',miejscowosc) LIKE ('%" + pole->Text + "%') ORDER BY nazwisko;", laczBaze);
    try
    {
        laczBaze->Open();
        MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
        moja->SelectCommand = zapytanie;
        DataTable^ tabela = gcnew DataTable();
        moja->Fill(tabela);
        BindingSource^ zrodlo = gcnew BindingSource();
        zrodlo->DataSource = tabela;
        siatka->DataSource = zrodlo;
        laczBaze->Close();
    }
    catch (Exception^ komunikat)
    {
        MessageBox::Show(komunikat->Message);
    }
    siatka->Columns[0]->Visible = false;
}

System::Void Gabinet::Program::klientSzukaj_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->pokazKklienta(this->txtKszukaj, this->siatkaKklient);
}

System::Void Gabinet::Program::siatkaKklient_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
{
    if (e->RowIndex >= 0)
    {
        zmienne::id_rekordu = Convert::ToInt32(this->siatkaKklient->Rows[e->RowIndex]->Cells[0]->Value);
        this->txtKimie->Text = this->siatkaKklient->Rows[e->RowIndex]->Cells["imie"]->Value->ToString();
        this->txtKnazwisko->Text = this->siatkaKklient->Rows[e->RowIndex]->Cells["nazwisko"]->Value->ToString();
        this->txtKemail->Text = this->siatkaKklient->Rows[e->RowIndex]->Cells["email"]->Value->ToString();
        this->txtKtelefon->Text = this->siatkaKklient->Rows[e->RowIndex]->Cells["telefon"]->Value->ToString();
        this->txtKulica->Text = this->siatkaKklient->Rows[e->RowIndex]->Cells["ulica"]->Value->ToString();
        this->txtKnumer->Text = this->siatkaKklient->Rows[e->RowIndex]->Cells["numer"]->Value->ToString();
        this->txtKkod_pocztowy->Text = this->siatkaKklient->Rows[e->RowIndex]->Cells["kod_pocztowy"]->Value->ToString();
        this->txtKmiejscowosc->Text = this->siatkaKklient->Rows[e->RowIndex]->Cells["miejscowosc"]->Value->ToString();
    }
    this->klientModyfikuj->Enabled = 1;
    this->klientUsun->Enabled = 1;
}

System::Void Gabinet::Program::klientDodaj_Click(System::Object^  sender, System::EventArgs^  e)
{
    if (this->txtKimie->Text->Length < 3 || this->txtKnazwisko->Text->Length <= 3 || this->txtKemail->Text->Length < 5
        || this->txtKtelefon->Text->Length != 11 || this->txtKulica->Text->Length < 3 || this->txtKnumer->Text->Length >
        4 || this->txtKkod_pocztowy->Text->Length != 6 || this->txtKmiejscowosc->Text->Length < 3)
    {
        MessageBox::Show("WprowadŸ poprawne dane ! ", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    else
    {
        MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
        MySqlCommand^ polecenie = laczBaze->CreateCommand();
        MySqlTransaction^ transakcja;
        laczBaze->Open();
        transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
        polecenie->Connection = laczBaze;
        polecenie->Transaction = transakcja;
        try
        {
            polecenie->CommandText = "INSERT INTO klient SET imie = '" + this->txtKimie->Text +
                "', nazwisko = '" + this->txtKnazwisko->Text + "', email = '" + this->txtKemail->Text + "', telefon = '" + this->txtKtelefon->Text +
                "', ulica = '" + this->txtKulica->Text + "', numer = '" + this->txtKnumer->Text + "', kod_pocztowy = '" +
                this->txtKkod_pocztowy->Text + "', miejscowosc = '" + this->txtKmiejscowosc->Text + "';";
            polecenie->ExecuteNonQuery();
            transakcja->Commit();
            MessageBox::Show("Wprpwadzono nowego klienta: " + txtKimie->Text + " " " " + txtKnazwisko->Text + "", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ komunikat)
        {
            MessageBox::Show(komunikat->Message);
            transakcja->Rollback();
        }
        this->pokazKklienta(this->txtKszukaj, this->siatkaKklient);
        laczBaze->Close();
    }
}

System::Void Gabinet::Program::klientModyfikuj_Click(System::Object^  sender, System::EventArgs^  e)
{
    if (this->txtKimie->Text->Length < 3 || this->txtKnazwisko->Text->Length <= 3 || this->txtKemail->Text->Length < 5
        || this->txtKtelefon->Text->Length != 11 || this->txtKulica->Text->Length < 3 || this->txtKnumer->Text->Length >
        4 || this->txtKkod_pocztowy->Text->Length != 6 || this->txtKmiejscowosc->Text->Length < 3)
    {
        MessageBox::Show("WprowadŸ poprawne dane ! ", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    else
    {
        MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
        MySqlCommand^ polecenie = laczBaze->CreateCommand();
        MySqlTransaction^ transakcja;
        laczBaze->Open();
        transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
        polecenie->Connection = laczBaze;
        polecenie->Transaction = transakcja;
        try
        {
            polecenie->CommandText = "UPDATE klient SET imie = '" + this->txtKimie->Text +
                "', nazwisko = '" + this->txtKnazwisko->Text + "', email = '" + this->txtKemail->Text + "', telefon = '" + this->txtKtelefon->Text +
                "', ulica = '" + txtKulica->Text + "', numer = '" + txtKnumer->Text + "', kod_pocztowy = '" +
                this->txtKkod_pocztowy->Text + "', miejscowosc = '" + this->txtKmiejscowosc->Text + "' WHERE klient_id = " + zmienne::id_rekordu + ";";
            polecenie->ExecuteNonQuery();
            transakcja->Commit();
            MessageBox::Show("Zmodyfikowano dane Klienta: " + txtKimie->Text + " " " " + txtKnazwisko->Text + "", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ komunikat)
        {
            MessageBox::Show(komunikat->Message);
            transakcja->Rollback();
        }
        this->pokazKklienta(this->txtKszukaj, this->siatkaKklient);
        laczBaze->Close();
    }
}

System::Void Gabinet::Program::klientUsun_Click(System::Object^  sender, System::EventArgs^  e)
{
    MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
    MySqlCommand^ polecenie = laczBaze->CreateCommand();
    MySqlTransaction^ transakcja;
    laczBaze->Open();
    transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
    polecenie->Connection = laczBaze;
    polecenie->Transaction = transakcja;
    try
    {
        if (MessageBox::Show("Czy na pewno usun¹æ wybranego Klienta ?", "Ostrze¿enie", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
        {
            polecenie->CommandText = "DELETE FROM wizyty WHERE klient_id = " + zmienne::id_rekordu + ";";
            polecenie->ExecuteNonQuery();
            polecenie->CommandText = "DELETE FROM klient WHERE klient_id = " + zmienne::id_rekordu + ";";
            polecenie->ExecuteNonQuery();
            transakcja->Commit();
            MessageBox::Show("Usuniêto klienta: " + this->txtKimie->Text + " " " " + this->txtKnazwisko->Text + " ", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    }
    catch (Exception^ komunikat)
    {
        MessageBox::Show(komunikat->Message);
        transakcja->Rollback();
    }
    this->pokazKklienta(this->txtKszukaj, this->siatkaKklient);
    this->wyczysc(this->daneKlienta);
    laczBaze->Close();
}

System::Void Gabinet::Program::rezerwacjaUszukaj_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->pokaz_us³ugi(this->txtRszukajU, this->siatkaRuslugi);
}

System::Void Gabinet::Program::rezerwacjaKszukaj_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->pokazKklienta(this->txtRszukajK, this->siatkaRklient);
}

System::Void Gabinet::Program::rezerwacjaPszukaj_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->pokazUzytkownika(this->txtRszukajP, this->siatkaRpracownik);
}

System::Void Gabinet::Program::siatkaRuslugi_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
{
    if (e->RowIndex >= 0)
    {
        zmienne::id_usluga = Convert::ToInt32(this->siatkaRuslugi->Rows[e->RowIndex]->Cells[0]->Value);
        this->txtRuslugi->Text = this->siatkaRuslugi->Rows[e->RowIndex]->Cells["nazwa"]->Value->ToString();
        MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
        MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT uzytkownik.uzytkownik_id, uzytkownik.imie AS Imie, uzytkownik.nazwisko AS Nazwisko, uzytkownik.uzytkownik_nazwa AS Login, uzytkownik.pracownik AS Pracownik FROM uzytkownik, uzytkownik_uslugi WHERE uzytkownik.uzytkownik_id = uzytkownik_uslugi.uzytkownik_id AND uzytkownik_uslugi.uslugi_id =" + zmienne::id_usluga + " AND uzytkownik.pracownik = 1;", laczBaze);
        try
        {
            laczBaze->Open();
            MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
            moja->SelectCommand = zapytanie;
            DataTable^ tabela = gcnew DataTable();
            moja->Fill(tabela);
            BindingSource^ zrodlo = gcnew BindingSource();
            zrodlo->DataSource = tabela;
            this->siatkaRpracownik->DataSource = zrodlo;
            laczBaze->Close();
        }
        catch (Exception^ komunikat)
        {
            MessageBox::Show(komunikat->Message);
        }
        this->siatkaRpracownik->Columns[0]->Visible = false;
    }
}

System::Void Gabinet::Program::siatkaRklient_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
{
    if (e->RowIndex >= 0)
    {
        zmienne::id_klient = Convert::ToInt32(this->siatkaRklient->Rows[e->RowIndex]->Cells[0]->Value);
        this->txtRklient->Text = this->siatkaRklient->Rows[e->RowIndex]->Cells["imie"]->Value->ToString() + " " + this->siatkaRklient->Rows[e->RowIndex]->Cells["nazwisko"]->Value->ToString();
    }
}

System::Void Gabinet::Program::siatkaRpracownik_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
{
    this->kalendarz->Enabled = true;
    zmienne::id_rekordu = e->RowIndex;
    zmienne::id_pracownik = zmienne::id_rekordu;
    this->pokaz_terminy();
}

void Gabinet::Program::pokaz_terminy()
{
    String^ czas;
    String^ praca_od;
    String^ praca_do;
    int licznik = 0;
    DateTime^ dzien_tygodnia = Convert::ToDateTime(data);
    int dzien = Convert::ToInt32(dzien_tygodnia->DayOfWeek);
    int g_start, g_stop;
    String^ klient = "";
    String^ usluga = "";

    if (zmienne::id_rekordu >= 0)
    {
        zmienne::id_pracownik = Convert::ToInt32(this->siatkaRpracownik->Rows[zmienne::id_rekordu]->Cells[0]->Value);
    }
    switch (dzien)
    {
    case 1:
        praca_od = "pon_od";
        praca_do = "pon_do";
        break;
    case 2:
        praca_od = "wt_od";
        praca_do = "wt_do";
        break;
    case 3:
        praca_od = "œr_od";
        praca_do = "œr_do";
        break;
    case 4:
        praca_od = "czw_od";
        praca_do = "czw_do";
        break;
    case 5:
        praca_od = "pt_od";
        praca_do = "pt_do";
        break;
    case 6:
        praca_od = "sob_od";
        praca_do = "sob_do";
        break;
    case 0:
        MessageBox::Show("Wybrany pracownik nie pracuje w niedzielê \n Wracam do poniedzia³ku");
        praca_od = "pon_od";
        praca_do = "pon_do";
        break;
    }
    MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
    laczbaze->Open();
    MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT date_format(" + praca_od + ", '%H') AS g_start, date_format(" + praca_do + ", '%H') AS g_stop FROM godziny WHERE uzytkownik_id = " + zmienne::id_pracownik + "", laczbaze);
    MySqlDataReader^ dane;
    dane = zapytanie->ExecuteReader();
    dane->Read();
    this->godziny->Controls->Clear();
    if (dane->HasRows)
    {
        g_start = Convert::ToInt32(dane->GetInt32("g_start"));
        g_stop = Convert::ToInt32(dane->GetInt32("g_stop"));
    }
    laczbaze->Close();
    for (int i = g_start; i < g_stop; i++)
    {
        for (int m = 0; m < 60; m += 30)
        {
            czas = data + " " + i + ":" + m + ":00";
            DateTime godzina = Convert::ToDateTime(czas);
            laczbaze->Open();
            MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT wizyty.wizyty_id, date_format(wizyty.rezerwacja_od, '%H:%i') AS Rod, date_format(wizyty.rezerwacja_do, '%H:%i') AS Rdo, uslugi.nazwa, klient.nazwisko FROM wizyty, uslugi, klient WHERE wizyty.rezerwacja_od = '" + godzina + "' AND wizyty.uzytkownik_id = " + zmienne::id_pracownik + " AND uslugi.uslugi_id = wizyty.uslugi_id AND klient.klient_id = wizyty.klient_id", laczbaze);
            MySqlDataReader^ dane;
            dane = zapytanie->ExecuteReader();
            dane->Read();
            TextBox^ poleGodziny = gcnew TextBox();
            this->godziny->Controls->Add(poleGodziny);
            poleGodziny->Width = 120;
            poleGodziny->BackColor = System::Drawing::Color::White;
            if (dane->HasRows)
            {
                poleGodziny->BackColor = System::Drawing::Color::Aqua;
                usluga = dane->GetString("nazwa");
                klient = dane->GetString("nazwisko");
                poleGodziny->Tag = dane->GetString("wizyty_id");
            }
            else
            {
                poleGodziny->BackColor = System::Drawing::Color::White;
                usluga = "";
                klient = "";
            }
            poleGodziny->Text = String::Format(godzina.ToShortTimeString()) + " " + usluga + " " + klient;
            poleGodziny->Click += gcnew System::EventHandler(this, &Program::Pole_klik);
            poleGodziny->Location = System::Drawing::Point(10, 20 + 25 * licznik);
            licznik++;
            laczbaze->Close();
        }
    }
}

System::Void Gabinet::Program::Pole_klik(System::Object^  sender, System::EventArgs^  e)
{
    TextBox^pole = safe_cast<TextBox^>(sender);
    godzina = pole->Text;
    txtRtermin->Text = data + " " + godzina;
    zmienne::id_wizyty = Convert::ToInt32(pole->Tag);
    MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
    laczbaze->Open();
    MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT CONCAT(klient.imie, ' ', klient.nazwisko ) AS klient, wizyty.klient_id, wizyty.uzytkownik_id, wizyty.uslugi_id, uslugi.nazwa FROM wizyty, klient, uslugi WHERE wizyty.wizyty_id = " + zmienne::id_wizyty + " AND klient.klient_id = wizyty.klient_id AND uslugi.uslugi_id = wizyty.uslugi_id", laczbaze);
    MySqlDataReader^ dane;
    dane = zapytanie->ExecuteReader();
    dane->Read();
    if (dane->HasRows)
    {
        this->txtRklient->Text = dane->GetString("klient");
        this->txtRuslugi->Text = dane->GetString("nazwa");
        zmienne::id_usluga = dane->GetInt32("uslugi_id");
        zmienne::id_klient = dane->GetInt32("klient_id");
        zmienne::id_pracownik = dane->GetInt32("uzytkownik_id");
    }
    laczbaze->Close();
    if (pole->BackColor == System::Drawing::Color::Aqua)
    {
        this->rezerwacjaModyfikuj->Enabled = true;
        this->rezerwacjaUsun->Enabled = true;
    }
    else
    {
        this->rezerwacjaModyfikuj->Enabled = false;
        this->rezerwacjaUsun->Enabled = false;
    }
}

System::Void Gabinet::Program::kalendarz_DateSelected(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e)
{
    data = String::Format(e->Start.ToShortDateString());
    this->txtRtermin->Text = data;
    this->pokaz_terminy();
}

System::Void Gabinet::Program::rezerwacjaDodaj_Click(System::Object^  sender, System::EventArgs^  e)
{
    if (zmienne::id_klient <= 0 || zmienne::id_usluga <= 0 || zmienne::id_pracownik <= 0 || this->txtRtermin->Text->Length < 14)
    {
        MessageBox::Show("WprowadŸ poprawne dane ! ", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    else
    {
        MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
        MySqlCommand^ polecenie = laczBaze->CreateCommand();
        MySqlTransaction^ transakcja;
        laczBaze->Open();
        transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
        polecenie->Connection = laczBaze;
        polecenie->Transaction = transakcja;
        try
        {
            DateTime^ rezerwacja_od = Convert::ToDateTime(data + " " + godzina);
            polecenie->CommandText = "INSERT INTO wizyty SET klient_id = " + zmienne::id_klient + ", uslugi_id = " + zmienne::id_usluga + ", uzytkownik_id = " + zmienne::id_pracownik + ", rezerwacja_od = '" + rezerwacja_od + "', rezerwacja_do = '" + rezerwacja_od + "', status = 'wyczekuje';";
            polecenie->ExecuteNonQuery();
            transakcja->Commit();
            MessageBox::Show("Rezerwacja zosta³a dodana do bazy danych", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ komunikat)
        {
            MessageBox::Show(komunikat->Message);
            transakcja->Rollback();
        }
        laczBaze->Close();
        this->pokaz_terminy();
    }
}

System::Void Gabinet::Program::rezerwacjaModyfikuj_Click(System::Object^  sender, System::EventArgs^  e)
{
    if (zmienne::id_klient <= 0 || zmienne::id_usluga <= 0 || zmienne::id_pracownik <= 0 || txtRtermin->Text->Length < 14)
    {
        MessageBox::Show("WprowadŸ poprawne dane ! ", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    else
    {
        MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
        MySqlCommand^ polecenie = laczBaze->CreateCommand();
        MySqlTransaction^ transakcja;
        laczBaze->Open();
        transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
        polecenie->Connection = laczBaze;
        polecenie->Transaction = transakcja;
        try
        {
            polecenie->CommandText = "UPDATE wizyty SET klient_id = " + zmienne::id_klient + ", uslugi_id = " + zmienne::id_usluga + ", uzytkownik_id = " + zmienne::id_pracownik + ", status = 'wyczekuje' WHERE wizyty_id = " + zmienne::id_wizyty + ";";
            polecenie->ExecuteNonQuery();
            transakcja->Commit();
            MessageBox::Show("Rezerwacja zosta³a zmodyfikowana", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ komunikat)
        {
            MessageBox::Show(komunikat->Message);
            transakcja->Rollback();
        }
        laczBaze->Close();
        this->pokaz_terminy();
    }
}

System::Void Gabinet::Program::rezerwacjaUsun_Click(System::Object^  sender, System::EventArgs^  e)
{
    MySqlConnection^laczBaze = gcnew MySqlConnection(konfiguracja);
    MySqlCommand^ polecenie = laczBaze->CreateCommand();
    MySqlTransaction^ transakcja;
    laczBaze->Open();
    transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
    polecenie->Connection = laczBaze;
    polecenie->Transaction = transakcja;
    try
    {
        if (MessageBox::Show("Czy na pewno usun¹æ wybran¹ rezerwacjê ?", "Ostrze¿enie", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
        {
            polecenie->CommandText = "DELETE FROM wizyty WHERE wizyty_id = " + zmienne::id_wizyty + ";";
            polecenie->ExecuteNonQuery();
            transakcja->Commit();
            MessageBox::Show("Usuniêto rezerwacjê", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    }
    catch (Exception^ komunikat)
    {
        MessageBox::Show(komunikat->Message);
        transakcja->Rollback();
    }
    laczBaze->Close();
    this->pokaz_terminy();
}

System::Void Gabinet::Program::menuRezerwacja_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->kontrola->SelectedTab = rezerwacja;
}

System::Void Gabinet::Program::menuKlienci_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->kontrola->SelectedTab = klienci;
}

System::Void Gabinet::Program::menuPraca_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->kontrola->SelectedTab = pracownik_uslugi;
}

System::Void Gabinet::Program::menuUslugi_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->kontrola->SelectedTab = uslugi;
}

System::Void Gabinet::Program::menuPracownicy_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->kontrola->SelectedTab = pracownicy;
}

System::Void Gabinet::Program::menuUstawienia_Click(System::Object^  sender, System::EventArgs^  e)
{
    this->kontrola->SelectedTab = zmiana_hasla;
}


