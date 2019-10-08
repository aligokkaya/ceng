 using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.IO;
using System.Timers;
using MySql.Data.MySqlClient;

namespace resimdondur
{
    public partial class Form1 : Form
    {
        string[] ports = SerialPort.GetPortNames();
        private void Timer1_Tick(object sender, EventArgs e)
        {
            try
            {
                string sonuc = serialPort1.ReadLine();
                string[] pot = sonuc.Split('*');
                // string sonuc = serialPort1.ReadExisting();//Serial.print kodu ile gelen analog veriyi alıyoruz,string formatında sonuc'a atıyoruz
                // label1.Text = sonuc + ""; //Labele yazdırıyoruz.
                lbl_akim.Text = pot[0];
                lbl_hız.Text = pot[1];

                //lbl_gerilim = pot[0];
                //lbl_sarj = pot[1];
                aGauge1.Value = Convert.ToInt32(pot[1]);
                aGauge2.Value = Convert.ToInt32(pot[0]);
                serialPort1.DiscardInBuffer();
                circle.Value = Convert.ToInt32(pot[1]);
                progressBar1.Value = Convert.ToInt32(pot[1]);
            }
            catch (Exception ex)
            {

            }
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            foreach (string port in ports)
            {
                comboBox1.Items.Add(port); // Port isimlerini combobox1'de gösteriyoruz.
                comboBox1.SelectedIndex = 0;
            }
            comboBox2.Items.Add("2400");  // Baudrate'leri kendimiz combobox2'ye giriyoruz.
            comboBox2.Items.Add("4800");
            comboBox2.Items.Add("9600");
            comboBox2.Items.Add("19200");
            comboBox2.Items.Add("115200");
            comboBox2.SelectedIndex = 2;
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            timer1.Start(); //250 ms olarak ayarladım timer'ı.
            if (serialPort1.IsOpen == false)
            {
                if (comboBox1.Text == "")
                    return;
                serialPort1.PortName = comboBox1.Text;  // combobox1'e zaten port isimlerini aktarmıştık.
                serialPort1.BaudRate = Convert.ToInt16(comboBox2.Text); //Seri Haberleşme baudrate'i combobox2 'de seçilene göre belirliyoruz.
                try
                {
                    serialPort1.Open(); //Haberleşme için port açılıyor
                                        //  label3.ForeColor = Color.Green;
                    label3.Text = "Bağlantı Açık";


                }
                catch (Exception hata)
                {
                    MessageBox.Show("Hata:" + hata.Message);
                }
            }
            
            else
            {
                label3.Text = "Bağlantı kurulu !!!";
            }

        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (serialPort1.IsOpen == true)
            {
                serialPort1.Close();
            }
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            timer1.Stop();
            serialPort1.Close();
        }

        private void Label3_Click(object sender, EventArgs e)
        {

        }

        private void ProgressBar1_Click(object sender, EventArgs e)
        {

        }

        private void AGauge3_ValueInRangeChanged(object sender, ValueInRangeChangedEventArgs e)
        {

        }

        private void ProgressBar1_Click_1(object sender, EventArgs e)
        {

        }

        private void Lbl_akim_Click(object sender, EventArgs e)
        {

        }

        private void Label4_Click(object sender, EventArgs e)
        {

        }

        private void Label5_Click(object sender, EventArgs e)
        {

        }
    }
}
