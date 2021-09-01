using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net.Mail;
using System.Configuration;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                MailMessage mail = new MailMessage();
                SmtpClient SmtpServer = new SmtpClient("smtp.gmail.com");
                mail.From = new MailAddress("xxxxx@gmail.com");
                mail.To.Add("yyyyyy@yahoo.com");
                mail.Subject = "Halo Boss";
                mail.Body = "Halo Boss, Super";
                mail.Priority = MailPriority.Normal;

                System.Net.Mail.Attachment attachment;
                attachment = new System.Net.Mail.Attachment("D:\\Default.aspx");
                mail.Attachments.Add(attachment);
                SmtpServer.Port = 587;
                SmtpServer.Credentials = new System.Net.NetworkCredential("sarjeelshakeelahmed@gmail.com", "poorpie1");
                SmtpServer.EnableSsl = true;

                SmtpServer.Send(mail);
                Console.Write("Email Terkirim");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }
    }
}

