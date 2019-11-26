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
    public partial class Form2 : Form
    {
        String[,] data;
        int x;
        public Form2()
        {
            InitializeComponent();
        }

        public Form2(int i, String[,] s)
        {
            InitializeComponent();
            data = s;
            x = i;
            textBox1.Text = data[i,0];
            textBox2.Text = data[i,2];
            char[] ch = data[i, 4].ToCharArray();
            for (int j = 0; j < data[i, 4].Length; j++)
            {
                if (ch[j] != ',' || ch[j] != ' ')
                {
                    textBox3.AppendText(ch[j].ToString());
                }
                else if (ch[j] == ',' || ch[j] == ' ')
                {
                    textBox3.AppendText("\n");
                }
            }
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form3 frm = new Form3(x, data);
            frm.Show();
            Form2 frm2 = new Form2();
            frm2.Hide();
        }
    }
}
