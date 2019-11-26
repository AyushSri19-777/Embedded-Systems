using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BankingApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public Form1(String[,] vals)
        {
            data = vals;
            InitializeComponent();
        }

        String[,] data = new String[3, 5] { { "UserName", "Password", "Balance", "Last Access Date", "Last 5 transactions" },
                                               { "sajal12", "sajal", "12345678", "", "-2000, +2000, -2000, +2000, -2000" },
                                               { "sajal23", "sajal", "12345678", "", "-2000, +2000, -2000, +2000, -2000" },
                                             };

        private void button1_Click(object sender, EventArgs e)
        {

            
            for (int i = 1; i < 3; i++)
            {
                if (textBox1.Text == data[i, 0] && textBox2.Text == data[i, 1])
                {
                    DateTime now = DateTime.Now;
                    data[i, 3] = ""+now;
                    Form2 frm = new Form2(i, data);
                    frm.Show();
                    Form1 frm1 = new Form1();
                    frm1.Hide();
                    break;
                }
                else if(i == 2)
                {
                    MessageBox.Show("Invalid Credentials");
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox2.Visible = false;
            label2.Visible = false;
            button2.Visible = false;
            textBox3.Visible = true;
            textBox4.Visible = true;
            label3.Visible = true;
            label4.Visible = true;
            button3.Visible = true;
            button1.Visible = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            for (int i = 1; i < 3; i++)
            {
                if (textBox1.Text == data[i, 0] && textBox3.Text == data[i, 1])
                {
                    data[i, 1] = textBox4.Text;
                    MessageBox.Show("Password Changed!");


                    textBox2.Visible = true;
                    label2.Visible = true;
                    button2.Visible = true;
                    textBox3.Visible = false;
                    textBox4.Visible = false;
                    label3.Visible = false;
                    label4.Visible = false;
                    button3.Visible = false;
                    button1.Visible = true;

                    break;
                }
                else if (i == 2)
                {
                    MessageBox.Show("Invalid Credentials");
                }
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
