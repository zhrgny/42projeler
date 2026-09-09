# 42projeler


Bu doküman, C programlama dilinin temel yapı taşlarını ve bellek yönetimini derinlemesine
kavramanı sağlayacak olan libft projesinin detaylı bir özetidir. Amacımız, standart C
kütüphanesindeki (libc) fonksiyonları kendi başımıza yeniden yazarak, ilerideki projelerimizde
güvenle kullanabileceğimiz sağlam bir araç kiti ( libft.a ) oluşturmaktır.

I. Genel Kurallar ve Teknik Gereksinimler

Tüm kodlar Norm kurallarına uygun olmalıdır. Bonus dosyaları da bu kurala tabidir.
Fonksiyonlar tanımsız davranışlar (undefined behavior) haricinde kesinlikle beklenmedik
şekilde çökmemelidir (segmentation fault, bus error, double free vb.). Aksi takdirde projeden
0 alırsınız.
Heap üzerinde ayrılan tüm bellek alanları (malloc ile) işi bittiğinde uygun şekilde serbest
bırakılmalıdır (free). Bellek sızıntılarına (memory leak) kesinlikle tolerans gösterilmez.
Global değişken kullanımı kesinlikle yasaktır.
Karmaşık bir fonksiyonu parçalara ayırmak için yardımcı fonksiyonlar yazmanız gerekirse,
bu fonksiyonları yalnızca bulundukları dosyada geçerli olmaları için static olarak
tanımlamalısınız.
Kütüphaneyi oluşturmak için ar komutu kullanılmalıdır. libtool kullanmak yasaktır.
Önemli Derleme Kuralları: Makefile dosyanız NAME , all , clean , fclean ve re kurallarını
mutlaka içermelidir. C dosyalarınız cc derleyicisi ile ve -Wall -Wextra -Werror bayrakları
zorunlu tutularak derlenmelidir.

II. Bölüm 1 - Libc Fonksiyonları
Bu bölümde, sistem standart kütüphanesinde yer alan fonksiyonların prototip ve davranışlarına
birebir uyan kopyalarını yazacaksınız. İsimlerinin başında ft_ ön eki bulunmalıdır.

Kritik Uyarılar:
1. restrict anahtar kelimesi C99 standardının bir parçasıdır. Kendi prototiplerinizde bu
kelimeyi kullanmanız ve kodunuzu -std=c99 bayrağıyla derlemeniz yasaktır.
2. Karakter sınıflandırma fonksiyonları (isalpha, isdigit, isalnum, isascii, isprint) için dönüş
değeri; karakter ilgili sınıfla eşleşiyorsa 1 , eşleşmiyorsa 0 olmalıdır.

Karakter ve Karakter Dizisi (String) Fonksiyonları
ft_isalpha , ft_isdigit , ft_isalnum , ft_isascii , ft_isprint : Karakterin türünü (harf,
rakam, yazdırılabilir vb.) kontrol eder.
ft_strlen : Bir karakter dizisinin uzunluğunu hesaplar.
ft_toupper , ft_tolower : Karakterleri büyük veya küçük harfe çevirir.
ft_strchr , ft_strrchr : Bir karakter dizisi içinde belirli bir karakteri baştan veya sondan
arar.
ft_strncmp : İki karakter dizisini belirli bir uzunluğa kadar karşılaştırır.
ft_strnstr : Bir karakter dizisi içinde başka bir karakter dizisini belirli bir uzunluğa kadar
arar.
ft_strlcpy , ft_strlcat : Güvenli bir şekilde string kopyalama ve birleştirme işlemleri
yapar (Glibc'de varsayılan olarak bulunmadığından test için <bsd/string.h> ve -lbsd
gerekebilir).
Bellek (Memory) Manipülasyonu Fonksiyonları
ft_memset : Bir bellek alanını belirli bir değer (byte) ile doldurur.
ft_bzero : Bir bellek alanını sıfırlarla ('\0') doldurur.
ft_memcpy : Bellek alanlarını kopyalar (alanların çakışmadığı varsayılır).
ft_memmove : Bellek alanlarını kopyalar (alanların çakışma ihtimaline karşı güvenlidir).
ft_memchr : Bir bellek alanında belirli bir byte değerini arar.
ft_memcmp : İki bellek alanını byte byte karşılaştırır.
Dinamik Bellek ve Dönüşüm Fonksiyonları
ft_atoi : String formatındaki bir sayıyı integer değere çevirir.
ft_calloc : Dinamik bellek ayırır ve içini sıfırlarla doldurur.
Özel Kural: Eğer nmemb veya size 0 ise, calloc free() fonksiyonuna sorunsuzca aktarılabilecek
benzersiz bir pointer döndürmelidir.


ft_strdup : Verilen string'in dinamik bellekte yeni bir kopyasını oluşturur.

III. Bölüm 2 - Ek Fonksiyonlar
Standart libc'de olmayan ancak 42 projelerinde hayat kurtaran özel fonksiyonlardır.
ft_substr
Orijinal string içinden, start indeksinden başlayan ve maksimum len uzunluğunda
olan yeni bir alt string (substring) oluşturur.

ft_strjoin
Verilen iki string'i (s1 ve s2) uç uca ekleyerek dinamik bellekte yeni bir string
oluşturur.

ft_strtrim
Verilen ana string'in başındaki ve sonundaki, set string'inde belirtilen karakterleri
kırpar.

ft_split
Bir string'i, belirtilen c karakterini ayırıcı olarak kullanarak kelimelere böler ve
dinamik olarak ayrılmış, NULL ile sonlandırılmış bir string dizisi (array) döndürür.
Bellek sızıntılarına en çok dikkat edilmesi gereken fonksiyondur.

ft_itoa
Verilen integer sayıyı (negatifler dahil) dinamik bellekte ayrılmış bir string'e çevirir.

ft_strmapi & ft_striteri
Bir stringin her bir karakteri üzerinde döngü kurarak, belirtilen bir fonksiyonu (f) her
karakterin üzerine uygular. Mapi yeni string döndürürken, iteri stringi kendi üzerinde
(referansla) değiştirir.
•

ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd
Karakter, string veya sayıları belirtilen dosya tanımlayıcısına (File Descriptor -
örneğin 1: stdout, 2: stderr) yazdırır.

IV. Bölüm 3 - Bağlı Liste (Linked List) Bonusları
Struct yapılarını kullanarak veri setlerini birbirine bağlayıp esnek listeler oluşturmanızı sağlar.
Veri yapısı şu şekilde olmalıdır:
typedef struct s_list
{
void *content;
struct s_list *next;
} t_list;
ft_lstnew : Yeni bir liste düğümü (node) oluşturur.
ft_lstadd_front / ft_lstadd_back : Listenin başına veya sonuna yeni düğüm ekler.
ft_lstsize : Listedeki toplam eleman sayısını sayar.
ft_lstlast : Listenin en sonundaki düğümü döndürür.
ft_lstdelone / ft_lstclear : Düğümün veya tüm listenin belleğini free kullanarak
güvenle temizler.
ft_lstiter / ft_lstmap : Listedeki tüm düğümler üzerinde gezinerek içlerindeki verilere
bir fonksiyon uygular.