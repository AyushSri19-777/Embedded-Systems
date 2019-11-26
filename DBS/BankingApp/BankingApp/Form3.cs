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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        String[,] data;
        int x;
        public Form3(int j, String[,] s)
        {
            InitializeComponent();
            data = s;
            x = j;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            for (int i = 1; i < 3; i++)
            {
                if (textBox1.Text == data[i, 0])
                {
                    DateTime now = DateTime.Now;
                    data[i, 3] = "" + now;
                    int transAmt = int.Parse(textBox2.Text);
                    int sendr = int.Parse(data[x,2]);
                    int receivr = int.Parse(data[i,2]);

                    if (transAmt > sendr)
                    {
                        MessageBox.Show("Amount exceeded");
                        break;
                    }
                    sendr = sendr - transAmt;
                    receivr = receivr + transAmt;

                    data[i, 2] = receivr.ToString();
                    data[x, 2] = sendr.ToString();
                    char[] receivrTrans = data[i, 4].ToCharArray();
                    char[] sendrTrans = data[x, 4].ToCharArray();

                    String receivrTransUpdate = "";
                    String sendrTransUpdate = "";
                    int flagComma = 0;

                    for (int k = 0; k < receivrTrans.Length; k++)
                    {
                        if (flagComma == 0)
                        {
                            if (receivrTrans[k] == ',')
                                flagComma = 1;
                        }
                        else
                        {
                            receivrTransUpdate += receivrTrans[k].ToString();
                        }
                    }
                    receivrTransUpdate += ", +" + transAmt;
                    data[i, 4] = receivrTransUpdate;

                    flagComma = 0;
                    for (int k = 0; k < sendrTrans.Length; k++)
                    {
                        if (flagComma == 0)
                        {
                            if (sendrTrans[k] == ',')
                                flagComma = 1;
                        }
                        else
                        {
                            sendrTransUpdate += sendrTrans[k].ToString();
                        }
                    }
                    sendrTransUpdate += ", -" + transAmt;
                    data[i, 4] = sendrTransUpdate;
                    Form1 frm1 = new Form1(data);
                    Form2 frm = new Form2(i, data);
                    frm.Show();
                    MessageBox.Show("Transaction Successful!");
                    break;
                }
                else if (i == 2)
                {
                    MessageBox.Show("Invalid Credentials");
                }
            }
        }
    }
}
