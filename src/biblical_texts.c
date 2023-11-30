/**
 * biblical-texts.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: This program print a Bible text and versicles in the terminal.
 *
 * Date: 16/10/2023
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "trace/trace.h"
#include "cutils/cutils.h"
#include "cutils/str.h"
#include "cutils/color.h"
#include "cutils/file.h"
#include "biblical_texts.h"

char gszConfFileName[_MAX_PATH];
char gszLogFileName[_MAX_PATH];
DebugLevel giDebugLevel = -1;
bool gbColoredLogLevel = false;

const char *gkpszProgramName;
STRUCT_COMMAND_LINE gstCmdLine;

static const char *kszOptStr = "hvt:d:cC:l:";

const char *gkpszEN_BiblicalTexts[] = {
/******************************************************************************
 *                                                                            *
 *                                OLD TESTMENT                                *
 *                                                                            *
 ******************************************************************************/

/**
 * Genesis
 */
// 000
"        In the beginning God created the Heaven, and the Earth.\n\
\n\
                         Genesis 1:1",
// 001
"        Therefore shall a man leave his father and his mother, and\n\
        shall cleave unto his wife: and they shalbe one flash.\n\
\n\
                         Genesis 2:24",
// 002
"        And they heard the voyce of the LORD God, walking in the\n\
        garden in the coole of the day: and Adam and his wife hid \n\
        themselues from the presence of the LORD God, amongst the trees\n\
        of the garden.\n\
\n\
                         Genesis 3:8",
// 003
"        And Enoch walked with God: and he was not; for God took him.\n\
\n\
                         Genesis 5:24",
// 004
"        And Abraham circumcised his sonne Isaac, being eight dayes\n\
        old, as God had commanded him.\n\
\n\
                         Genesis 21:4",
// 005
"        And Isaac intreated the LORD for his wife, because she was\n\
        barren: and the LORD was intreated of him, and Rebekah his\n\
        wife conceived.\n\
\n\
                         Genesis 25:21",
// 006
"        And God sent me before you to preserve you a posterity in the\n\
        earth, and to save your lives by a great deliverance.\n\
        So now it was not you that sent me hither, but God: and he\n\
        hath made me a father to Pharaoh, and lord of all his house,\n\
        and a ruler throughout all the land of Egypt.\n\
\n\
                         Genesis 45:7, 8",

/**
 * Exodus
 */
// 007
"        But the more they afflicted them, the more they multiplied\n\
        and grew. And they were grieved because of the children of\n\
        Israel.\n\
\n\
                         Exodus 1:12",
// 008
"        Therefore God dealt well with the midwives: and the people\n\
        multiplied, and waxed very mighty.\n\
\n\
                         Exodus 1:20",
// 009
"        And the angel of the LORD appeared unto him in a flame of\n\
        fire out of the midst of a bush: and he looked, and, behold,\n\
        the bush burned with fire, and the bush was not consumed.\n\
\n\
                         Exodus 3:2",
// 010
"        And God said unto Moses, I AM THAT I AM: and he said, Thus\n\
        shalt thou say unto the children of Israel, I AM hath sent me\n\
        unto you.\n\
\n\
                         Exodus 3:14",
// 011
"        And the LORD said unto Moses, When thou goest to return into\n\
        Egypt, see that thou do all those wonders before Pharaoh,\n\
        which I have put in thine hand: but I will harden his heart,\n\
        that he shall not let the people go.\n\
\n\
                         Exodus 4:21",
// 012
"        And it came to pass by the way in the inn, that the LORD\n\
        met him, and sought to kill him.\n\
        Then Zipporah took a sharp stone, and cut off the foreskin\n\
        of her son, and cast it at his feet, and said, Surely a bloody\n\
        husband art thou to me.\n\
        So he let him go: then she said, A bloody husband thou art,\n\
        because of the circumcision.\n\
\n\
                         Exodus 4:24-26",
// 013
"        And I will harden Pharaoh's heart, and multiply my signs and\n\
        my wonders in the land of Egypt.\n\
\n\
                         Exodus 7:3",
// 014
"        Now the sojourning of the children of Israel, who dwelt in\n\
        Egypt, was four hundred and thirty years.\n\
\n\
                         Exodus 12:40",
// 015
"        And the LORD said unto Moses and Aaron, This is the ordinance\n\
        of the passover: There shall no stranger eat thereof:\n\
        But every man's servant that is bought for money, when thou\n\
        hast circumcised him, then shall he eat thereof.\n\
\n\
                         Exodus 12:43, 44",
// 016
"        And Moses chose able men out of all Israel, and made them\n\
        heads over the people, rulers of thousands, rulers of hundreds,\n\
        rulers of fifties, and rulers of tens.\n\
\n\
                         Exodus 18:25",
// 017
"        And he took the book of the covenant, and read in the audience\n\
        of the people: and they said, All that the LORD hath said\n\
        will we do, and be obedient.\n\
\n\
                         Exodus 24:7",
// 018
"        And Moses went into the midst of the cloud, and gat him up\n\
        into the mount: and Moses was in the mount forty days and forty nights.\n\
\n\
                         Exodus 24:18",
// 019
"        And look that thou make them after their pattern, which was\n\
        shewed thee in the mount.\n\
\n\
                         Exodus 25:40",
// 020
"        And the anointing oil, and sweet incense for the holy place:\n\
        according to all that I have commanded thee shall they do.\n\
\n\
                         Exodus 31:11",
// 021
"        Yet now, if thou wilt forgive their sin--; and if not, blot\n\
        me, I pray thee, out of thy book which thou hast written.\n\
\n\
                         Exodus 32:32",
// 022
"        And he said, I will make all my goodness pass before thee,\n\
        and I will proclaim the name of the LORD before thee; and will\n\
        be gracious to whom I will be gracious, and will shew mercy on\n\
        whom I will shew mercy.\n\
\n\
                         Exodus 33:19",
// 023
"        Take heed to thyself, lest thou make a covenant with the\n\
        inhabitants of the land whither thou goest, lest it be for\n\
        a snare in the midst of thee:\n\
        But ye shall destroy their altars, break their images, and\n\
        cut down their groves:\n\
        For thou shalt worship no other god: for the LORD, whose name\n\
        is Jealous, is a jealous God:\n\
        Lest thou make a covenant with the inhabitants of the land,\n\
        and they go a whoring after their gods, and do sacrifice unto\n\
        their gods, and one call thee, and thou eat of his sacrifice;\n\
        And thou take of their daughters unto thy sons, and their daughters\n\
        go a whoring after their gods, and make thy sons go a whoring after\n\
        their gods.\n\
\n\
                         Exodus 34:12-16",

/**
 * Leviticus
 */
// 024
"        Thou shalt not avenge, nor bear any grudge against the children\n\
        of thy people, but thou shalt love thy neighbour as thyself:\n\
        I am the LORD.\n\
\n\
                         Leviticus 19:18",
// 025
"        And ye shall be holy unto me: for I the LORD am holy, and have\n\
        severed you from other people, that ye should be mine.\n\
\n\
                         Leviticus 20:26",
// 026
"        Thou shalt sanctify him therefore; for he offereth the bread\n\
        of thy God: he shall be holy unto thee: for I the LORD, which\n\
        sanctify you, am holy.\n\
\n\
                         Leviticus 21:8",

/**
 * Numbers
 */
// 027
"        And Nadab and Abihu died before the LORD, when they offered\n\
        strange fire before the LORD, in the wilderness of Sinai, and\n\
        they had no children: and Eleazar and Ithamar ministered in the\n\
        priest's office in the sight of Aaron their father.\n\
\n\
                         Numbers 3:4 ",

/**
 * Deuteronomy
 */
// 028
"        If there arise among you a prophet, or a dreamer of dreams,\n\
        and giveth thee a sign or a wonder,\n\
        And the sign or the wonder come to pass, whereof he spake unto\n\
        thee, saying, Let us go after other gods, which thou hast not\n\
        known, and let us serve them;\n\
        Thou shalt not hearken unto the words of that prophet, or that\n\
        dreamer of dreams: for the LORD your God proveth you, to know\n\
        whether ye love the LORD your God with all your heart and with\n\
        all your soul.\n\
        Ye shall walk after the LORD your God, and fear him, and keep\n\
        his commandments, and obey his voice, and ye shall serve him,\n\
        and cleave unto him.\n\
        And that prophet, or that dreamer of dreams, shall be put to\n\
        death; because he hath spoken to turn you away from the LORD\n\
        your God, which brought you out of the land of Egypt, and redeemed\n\
        you out of the house of bondage, to thrust thee out of the way which\n\
        the LORD thy God commanded thee to walk in. So shalt thou put\n\
        the evil away from the midst of thee.\n\
\n\
                         Deuteronomy 13:1-5",
// 029
"        But the prophet, which shall presume to speak a word in my\n\
        name, which I have not commanded him to speak, or that shall\n\
        speak in the name of other gods, even that prophet shall die.\n\
        And if thou say in thine heart, How shall we know the word which\n\
        the LORD hath not spoken?\n\
        When a prophet speaketh in the name of the LORD, if the thing\n\
        follow not, nor come to pass, that is the thing which the LORD\n\
        hath not spoken, but the prophet hath spoken it presumptuously:\n\
        thou shalt not be afraid of him.\n\
                         Deuteronomy 18:20-22",
// 030
"        He is the Rock, his work is perfect: for all his ways are judgment:\n\
        a God of truth and without iniquity, just and right is he.\n\
\n\
                         Deuteronomy 32:4",
// 031
"        And there arose not a prophet since in Israel like unto Moses,\n\
        whom the LORD knew face to face,\n\
\n\
                         Deuteronomy 34:10",

/**
 * Joshua
 */
// 032
"        Only be thou strong and very courageous, that thou mayest observe\n\
        to do according to all the law, which Moses my servant commanded thee:\n\
        turn not from it to the right hand or to the left, that thou mayest\n\
        prosper whithersoever thou goest.\n\
\n\
                         Joshua 1:7",

/**
 * Judges
 */
// 033
"        Now these are the nations which the LORD left, to prove Israel by\n\
        them, even as many of Israel as had not known all the wars of Canaan;\n\
        Only that the generations of the children of Israel might know, to teach\n\
        them war, at the least such as before knew nothing thereof;\n\
        Namely, five lords of the Philistines, and all the Canaanites, and the\n\
        Sidonians, and the Hivites that dwelt in mount Lebanon, from mount Baalhermon\n\
        unto the entering in of Hamath.\n\
        And they were to prove Israel by them, to know whether they would hearken\n\
        unto the commandments of the LORD, which he commanded their fathers by the\n\
        hand of Moses.\n\
        And the children of Israel dwelt among the Canaanites, Hittites, and Amorites,\n\
        and Perizzites, and Hivites, and Jebusites:\n\
        And they took their daughters to be their wives, and gave their daughters to\n\
        their sons, and served their gods.\n\
        And the children of Israel did evil in the sight of the LORD, and forgat the\n\
        LORD their God, and served Baalim and the groves.\n\
\n\
                         Judges 3:1-7",

/**
 * Ruth
 */
// 034
"        And they lifted up their voice, and wept again: and Orpah kissed\n\
        her mother in law; but Ruth clave unto her.\n\
        And she said, Behold, thy sister in law is gone back unto her people,\n\
        and unto her gods: return thou after thy sister in law.\n\
        And Ruth said, Intreat me not to leave thee, or to return from following\n\
        after thee: for whither thou goest, I will go; and where thou lodgest, I\n\
        will lodge: thy people shall be my people, and thy God my God:\n\
\n\
                         Ruth 1:14-16",

/**
 * 1 Samuel
 */
// 035
"        For this child I prayed; and the LORD hath given me my petition\n\
        which I asked of him:\n\
\n\
                          1 Samuel 1:27",
// 036
"        The LORD killeth, and maketh alive: he bringeth down to the\n\
        grave, and bringeth up.\n\
\n\
                          1 Samuel 2:6",
// 037
"        If one man sin against another, the judge shall judge him:\n\
        but if a man sin against the LORD, who shall intreat for him?\n\
        Notwithstanding they hearkened not unto the voice of their father,\n\
        because the LORD would slay them.\n\
\n\
                          1 Samuel 2:25",


/**
 * 2 Samuel
 */
// 038
"        And when they came to Nachon's threshingfloor, Uzzah put forth\n\
        his hand to the ark of God, and took hold of it; for the oxen\n\
        shook it.\n\
        And the anger of the LORD was kindled against Uzzah; and God smote\n\
        him there for his error; and there he died by the ark of God.\n\
\n\
                          2 Samuel 6:6, 7",

/**
 * 1 Kings
 */
// 039
"        For it came to pass, when Solomon was old, that his wives turned\n\
        away his heart after other gods: and his heart was not perfect with\n\
        the LORD his God, as was the heart of David his father.\n\
\n\
                          1 Kings 11:4",
// 040
"        And it came to pass at the time of the offering of the evening\n\
        sacrifice, that Elijah the prophet came near, and said, LORD God\n\
        of Abraham, Isaac, and of Israel, let it be known this day that\n\
        thou art God in Israel, and that I am thy servant, and that I have\n\
        done all these things at thy word.\n\
        Hear me, O LORD, hear me, that this people may know that thou art\n\
        the LORD God, and that thou hast turned their heart back again.\n\
\n\
                          1 Kings 18:36, 37",

/**
 * 2 Kings
 */
// 041
"        And she said unto her husband, Behold now, I perceive that\n\
        this is an holy man of God, which passeth by us continually.\n\
\n\
                          2 Kings 4:9",

/**
 * 1 Chronicles
 */
// 042
"        For great is the LORD, and greatly to be praised: he also is to\n\
        be feared above all gods.\n\
        For all the gods of the people are idols: but the LORD made the\n\
        heavens.\n\
                          1 Chronicles 16:25, 26",

/**
 * 2 Chronicles
 */
// 043
"        And it came to pass, when the king had heard the words of the law,\n\
        that he rent his clothes.\n\
\n\
                          2 Chronicles 34:19",

/**
 * Ezra
 */
// 044
"        For Ezra had prepared his heart to seek the law of the LORD, and to\n\
        do it, and to teach in Israel statutes and judgments.\n\
\n\
                          Ezra 7:10",

/**
 * Nehemiah
 */
// 045
"        And that we would not give our daughters unto the people of the land,\n\
        nor take their daughters for our sons:\n\
\n\
                          Nehemiah 10:30",

/**
 * Esther
 */
// 046
"        Go, gather together all the Jews that are present in Shushan, and fast\n\
        ye for me, and neither eat nor drink three days, night or day: I also and\n\
        my maidens will fast likewise; and so will I go in unto the king, which\n\
        is not according to the law: and if I perish, I perish.\n\
\n\
                          Esther 4:16",

/**
 * Job
 */
// 047 
"        There was a man in the land of Uz, whose name was Job; and that man was\n\
        perfect and upright, and one that feared God, and eschewed evil.\n\
\n\
                          Job 1:1",

/**
 * Psalms
 */
// 048
"        Blessed is the man that walketh not in the counsel of the ungodly, nor\n\
        standeth in the way of sinners, nor sitteth in the seat of the scornful.\n\
\n\
                          Psalms 1:1",

/**
 * Proverbs
 */
// 049
"        He that spareth his rod hateth his son: but he that loveth him chasteneth him betimes.\n\
\n\
                          Proverbs 13:24",

/**
 * Ecclesiates
 */
// 050
"        Remember now thy Creator in the days of thy youth, while the evil days\n\
        come not, nor the years draw nigh, when thou shalt say, I have no pleasure\n\
        in them;\n\
\n\
                          Ecclesiates 12:1",

/**
 * Song of Solomon
 */
// 051
"        Many waters cannot quench love, neither can the floods drown it: if a man would\n\
        give all the substance of his house for love, it would utterly be contemned.\n\
\n\
                          Song of Solomon 8:7",

/**
 * Isaiah
 */
// 052
"        And one cried unto another, and said, Holy, holy, holy, is the LORD of hosts: the\n\
        whole earth is full of his glory.\n\
\n\
                          Isaiah 6:3",

/**
 * Jeremiah
 */
// 053
"        Before I formed thee in the belly I knew thee; and before thou camest forth out of the womb I\n\
        sanctified thee, and I ordained thee a prophet unto the nations.\n\
        Then said I, Ah, Lord GOD! behold, I cannot speak: for I am a child.\n\
        But the LORD said unto me, Say not, I am a child: for thou shalt go to all that I shall send thee,\n\
        and whatsoever I command thee thou shalt speak.\n\
\n\
                          Jeremiah 1:5-7",

/**
 * Lamentations
 */
// 
"",

/**
 * Ezekiel
 */
// 
"        Thus saith the Lord GOD; Woe unto the foolish prophets, that follow their own spirit,\n\
        and have seen nothing!\n\
\n\
                          Ezekiel 13:3",

/**
 * Daniel
 */
// 
"       And he changeth the times and the seasons: he removeth kings, and setteth up kings: he\n\
       giveth wisdom unto the wise, and knowledge to them that know understanding:\n\
\n\
                          Daniel 2:21",

/**
 * Hosea
 */
// 
"       I have written to him the great things of my law, but they were counted as a strange thing.\n\
\n\
                          Hosea 8:12",

/**
 * Joel
 */
// 
"       And it shall come to pass afterward, that I will pour out my spirit upon all flesh; and your\n\
       sons and your daughters shall prophesy, your old men shall dream dreams, your young men shall\n\
       see visions:\n\
       And also upon the servants and upon the handmaids in those days will I pour out my spirit.\n\
\n\
                          Joel 2:28, 29",

/**
 * Amos
 */
// 
"      Behold, the days come, saith the Lord GOD, that I will send a famine in the land, not a famine\n\
      of bread, nor a thirst for water, but of hearing the words of the LORD:\n\
      And they shall wander from sea to sea, and from the north even to the east, they shall run to and\n\
      fro to seek the word of the LORD, and shall not find it.\n\
\n\
                          Amos 8:11, 12",

/**
 * Obadiah
 */
// 
"",

/**
 * Jonah
 */
// 
"",

/**
 * Micah
 */
// 
"",

/**
 * Nahum
 */
// 
"",

/**
 * Habakkuk
 */
// 
"",

/**
 * Zephaniah
 */
// 
"",

/**
 * Haggai
 */
// 
"",

/**
 * Zechariah
 */
// 
"     For the idols have spoken vanity, and the diviners have seen a lie, and have told false dreams;\n\
     they comfort in vain: therefore they went their way as a flock, they were troubled, because there was no shepherd.\n\
\n\
                         Zechariah 10:2",

/**
 * Malachi
 */
// 
"",

/******************************************************************************
 *                                                                            *
 *                                NEW TESTMENT                                *
 *                                                                            *
 ******************************************************************************/

/**
 * Matthew
 */
// 
"",

/**
 * Mark
 */
// 
"",

/**
 * Luke
 */
// 
"",

/**
 * John
 */
// 
"        In the beginning was the Word, and the Word was with God, and the Word\n\
        was God.\n\
\n\
                             Jonh 1:1",
// 
"        For God so loved the world, that he gave his olnly begotten\n\
        Sonne: that whosoever beleeveth in him, should not perish,\n\
        but have everlasting life.\n\
\n\
                             Jonh 3:16"

/**
 * Acts
 */
// 
"",

/**
 * Romans
 */
// 
"",

/**
 * 1 Corinthians
 */
// 
"",

/**
 * 2 Corinthians
 */
// 
"",

/**
 * Galatians
 */
// 
"",

/**
 * Ephesians
 */
// 
"",

/**
 * Philippians
 */
// 
"",

/**
 * Colossians
 */
// 
"",

/**
 * 1 Thessalonians
 */
// 
"",

/**
 * 2 Thessalonians
 */
// 
"",

/**
 * 1 Timothy
 */
// 
"",

/**
 * 2 Timothy
 */
// 
"",

/**
 * Titus
 */
// 
"",

/**
 * Philemon
 */
// 
"",

/**
 * Hebrews
 */
// 
"",

/**
 * James
 */
// 
"",

/**
 * 1 Peter
 */
// 
"",

/**
 * 2 Peter
 */
// 
"",

/**
 * 1 John
 */
// 
"",

/**
 * 2 John
 */
// 
"",

/**
 * 3 John
 */
// 
"",

/**
 * Jude
 */
// 
"",

/**
 * Revelation
 */
// 
"",

NULL
};

const char *gkpszBR_BiblicalTexts[] = {
/******************************************************************************
 *                                                                            *
 *                                OLD TESTMENT                                *
 *                                                                            *
 ******************************************************************************/

/**
 * Genesis
 */
// 000
"        NO princípio criou Deus os céus e a terra.\n\
\n\
                         Gênesis 1:1",
// 001
"        Portanto deixará o homem o seu pai e a sua mãe, e \n\
        apeger-se-a à sua mulher, e serão ambos uma carne.\n\
\n\
                         Gênesis 2:24",
// 002
"        E ouviram a voz do Senhor Deus, que passeava no jardim pela\n\
        viração do dia; e esconderam-se Adão e sua mulher da presença\n\
        do Senhor Deus, entre as árvores do jardim.\n\
\n\
                         Gênesis 3:8",
// 003
"        E andou Enoque com Deus; e não apareceu mais, porquanto Deus\n\
        para si o tomou.\n\
\n\
                         Gênesis 5:24",
// 004
"        E Abraão circuncidou o seu filho Isaque, quando era da idade\n\
        de oito dias, como Deus lhe tinha ordenado.\n\
\n\
                         Gênesis 21:4",
// 005
"        E Isaque orou insistentemente ao Senhor por sua mulher,\n\
        porquanto era estéril; e o Senhor ouviu as suas orações, e\n\
        Rebeca sua mulher concebeu.\n\
\n\
                         Gênesis 25:21",
// 006
"        Pelo que Deus me enviou adiante de vós, para conservar vossa\n\
        sucessão na terra, e para guardar-vos em vida por um grande\n\
        livramento.\n\
        Assim não fostes vós que me enviastes para cá, senão Deus,\n\
        que me tem posto por pai de Faraó, e por senhor de toda a sua\n\
        casa, e como regente em toda a terra do Egito.\n\
\n\
                         Gênesis 45:7, 8",
         
/**      
 * Exodus
 */
// 007
"        Mas quanto mais os afligiam, tanto mais se multiplicavam,\n\
        e tanto mais cresciam; de maneira que se enfadavam por causa\n\
        dos filhos de Israel.\n\
\n\
                         Êxodo 1:12",
// 008
"        Portanto Deus fez bem às parteiras. E o povo se aumentou,\n\
        e se fortaleceu muito.\n\
\n\
                         Êxodo 1:20",
// 009
"        E apareceu-lhe o anjo do Senhor em uma chama de fogo do meio\n\
        duma sarça; e olhou, e eis que a sarça ardia no fogo, e a sarça\n\
        não se consumia.\n\
\n\
                         Êxodo 3:2",
// 010
"        E disse Deus a Moisés: EU SOU O QUE SOU. Disse mais: Assim\n\
        dirás aos filhos de Israel: EU SOU me enviou a vós.\n\
\n\
                         Êxodo 3:14",
// 011
"        E disse o Senhor a Moisés: Quando voltares ao Egito, atenta\n\
        que faças diante de Faraó todas as maravilhas que tenho posto\n\
        na tua mão; mas eu lhe endurecerei o coração, para que não\n\
        deixe ir o povo.\n\
\n\
                         Êxodo 4:21",
// 012
"        E aconteceu no caminho, numa estalagem, que o Senhor o encontrou,\n\
        e o quis matar.\n\
        Então Zípora tomou uma pedra aguda, e circuncidou o prepúcio\n\
        de seu filho, e lançou-o a seus pés, e disse: Certamente me\n\
        és um esposo sanguinário.\n\
        E desviou-se dele. Então ela disse: Esposo sanguinário, por\n\
        causa da circuncisão.\n\
\n\
                         Êxodo 4:24-26",
// 013
"        Eu, porém, endurecerei o coração de Faraó, e multiplicarei\n\
        na terra do Egito os meus sinais e as minhas maravilhas.\n\
\n\
                         Êxodo 7:3",
// 014
"        O tempo que os filhos de Israel habitaram no Egito foi de\n\
        quatrocentos e trinta anos.\n\
\n\
                         Êxodo 12:40",
// 015
"        Disse mais o Senhor a Moisés e a Arão: Esta é a ordenança da\n\
        páscoa: nenhum filho do estrangeiro comerá dela.\n\
        Porém todo o servo comprado por dinheiro, depois que o houveres\n\
        circuncidado, então comerá dela.\n\
\n\
                         Êxodo 12:43, 44",
// 016
"        E escolheu Moisés homens capazes, de todo o Israel, e os pôs\n\
        por cabeças sobre o povo; maiorais de mil, maiorais de cem,\n\
        maiorais de cinquenta e maiorais de dez.\n\
\n\
                         Êxodo 18:25",
// 017
"        E tomou o livro da aliança e o leu aos ouvidos do povo, e\n\
        eles disseram: Tudo o que o Senhor tem falado faremos, e obedeceremos.\n\
\n\
                         Êxodo 24:7",
// 018
"        E Moisés entrou no meio da nuvem, depois que subiu ao monte;\n\
        e Moisés esteve no monte quarenta dias e quarenta noites.\n\
\n\
                         Êxodo 24:18",
// 019
"        Atenta, pois, que o faças conforme ao seu modelo, que te foi\n\
        mostrado no monte.\n\
\n\
                         Êxodo 25:40",
// 020
"        E o azeite da unção, e o incenso aromático para o santuário;\n\
        farão conforme a tudo que te tenho mandado.\n\
\n\
                         Êxodo 31:11",
// 021
"        Agora, pois, perdoa o seu pecado; se não, risca-me, peço-te,\n\
        do teu livro, que tens escrito.\n\
\n\
                         Êxodo 32:32",
// 022
"        Porém ele disse: Eu farei passar toda a minha bondade por\n\
        diante de ti, e proclamarei o nome do Senhor diante de ti; e\n\
        terei misericórdia de quem eu tiver misericórdia, e me\n\
        compadecerei de quem eu me compadecer.\n\
\n\
                         Êxodo 33:19",
// 023
"        Guarda-te de fazeres aliança com os moradores da terra aonde\n\
        hás de entrar; para que não seja por laço no meio de ti.\n\
        Mas os seus altares derrubareis, e as suas estátuas quebrareis,\n\
        e os seus bosques cortareis.\n\
        Porque não te inclinarás diante de outro deus; pois o nome do\n\
        Senhor é Zeloso; é um Deus zeloso.\n\
        Para que não faças aliança com os moradores da terra, e quando\n\
        eles se prostituírem após os seus deuses, ou sacrificarem aos\n\
        seus deuses, tu, como convidado deles, comas também dos seus\n\
        sacrifícios,\n\
        E tomes mulheres das suas filhas para os teus filhos, e suas\n\
        filhas, prostituindo-se com os seus deuses, façam que também\n\
        teus filhos se prostituam com os seus deuses.\n\
\n\
                         Êxodo 34:12-16",

/**
 * Leviticus
 */
// 024
"        Não te vingarás nem guardarás ira contra os filhos do teu povo;\n\
        mas amarás o teu próximo como a ti mesmo. Eu sou o Senhor.\n\
\n\
                         Levítico 19:18",
// 025
"        E ser-me-eis santos, porque eu, o Senhor, sou santo, e vos\n\
        separei dos povos, para serdes meus.\n\
\n\
                         Levítico 20:26",
// 026
"        Portanto o santificarás, porquanto oferece o pão do teu Deus;\n\
        santo será para ti, pois eu, o Senhor que vos santifica, sou santo.\n\
\n\
                         Levítico 21:8",

/**
 * Numbers
 */
// 027
"        Mas Nadabe e Abiú morreram perante o Senhor, quando ofereceram\n\
        fogo estranho perante o Senhor no deserto de Sinai, e não tiveram\n\
        filhos; porém Eleazar e Itamar administraram o sacerdócio diante\n\
        de Arão, seu pai.\n\
\n\
                         Números 3:4",

/**
 * Deuteronomy
 */
// 028
"        Quando profeta ou sonhador de sonhos se levantar no meio de\n\
        ti, e te der um sinal ou prodígio,\n\
        E suceder o tal sinal ou prodígio, de que te houver falado,\n\
        dizendo: Vamos após outros deuses, que não conheceste, e\n\
        sirvamo-los;\n\
        Não ouvirás as palavras daquele profeta ou sonhador de sonhos;\n\
        porquanto o Senhor vosso Deus vos prova, para saber se amais o\n\
        Senhor vosso Deus com todo o vosso coração, e com toda a vossa alma.\n\
        Após o Senhor vosso Deus andareis, e a ele temereis, e os seus\n\
        mandamentos guardareis, e a sua voz ouvireis, e a ele servireis,\n\
        e a ele vos achegareis.\n\
        E aquele profeta ou sonhador de sonhos morrerá, pois falou rebeldia\n\
        contra o Senhor vosso Deus, que vos tirou da terra do Egito, e vos\n\
        resgatou da casa da servidão, para te apartar do caminho que te ordenou\n\
        o Senhor teu Deus, para andares nele: assim tirarás o mal do meio de ti.\n\
\n\
                         Deuteronômio 13:1-5",
// 029
"        Porém o profeta que tiver a presunção de falar alguma palavra\n\
        em meu nome, que eu não lhe tenha mandado falar, ou o que falar\n\
        em nome de outros deuses, esse profeta morrerá.\n\
        E, se disseres no teu coração: Como conhecerei a palavra que o\n\
        Senhor não falou?\n\
        Quando o profeta falar em nome do Senhor, e essa palavra não se\n\
        cumprir, nem suceder assim; esta é palavra que o Senhor não falou;\n\
        com soberba a falou aquele profeta; não tenhas temor dele.\n\
\n\
                         Deuteronômio 18:20-22",
// 030
"        Ele é a Rocha, cuja obra é perfeita, porque todos os seus caminhos\n\
        justos são; Deus é a verdade, e não há nele injustiça; justo e reto é.\n\
\n\
                         Deuteronômio 32:4",
// 031
"        E nunca mais se levantou em Israel profeta algum como Moisés,\n\
        a quem o Senhor conhecera face a face;\n\
\n\
                         Deuteronômio 34:10",

/**
 * Joshua
 */
// 032
"        Tão-somente esforça-te e tem mui bom ânimo, para teres o cuidado\n\
        de fazer conforme a toda a lei que meu servo Moisés te ordenou; dela\n\
        não te desvies, nem para a direita nem para a esquerda, para que\n\
        prudentemente te conduzas por onde quer que andares.\n\
\n\
                         Josué 1:7",

/**
 * Judges
 */
// 033
"        Estas, pois, são as nações que o SENHOR deixou ficar, para\n\
        por elas provar a Israel, a saber, a todos os que não sabiam\n\
        de todas as guerras de Canaã.\n\
        Tão-somente para que as gerações dos filhos de Israel delas\n\
        soubessem (para lhes ensinar a guerra), pelo menos os que dantes\n\
        não sabiam delas.\n\
        Cinco príncipes dos filisteus, e todos os cananeus, e sidônios,\n\
        e heveus que habitavam nas montanhas do Líbano desde o monte de\n\
        Baal-Hermom, até à entrada de Hamate.\n\
        Estes, pois, ficaram, para por eles provar a Israel, para saber\n\
        se dariam ouvido aos mandamentos do Senhor, que ele tinha ordenado\n\
        a seus pais, pelo ministério de Moisés.\n\
        Habitando, pois, os filhos de Israel no meio dos cananeus, dos\n\
        heteus, e amorreus, e perizeus, e heveus, e jebuseus,\n\
        Tomaram de suas filhas para si por mulheres, e deram as suas filhas\n\
        aos filhos deles; e serviram aos seus deuses.\n\
        E os filhos de Israel fizeram o que era mau aos olhos do Senhor,\n\
        e se esqueceram do Senhor seu Deus; e serviram aos baalins e a Astarote.\n\
\n\
                         Juízes 3:1-7",

/**
 * Ruth
 */
// 034
"        Então levantaram a sua voz, e tornaram a chorar; e Orfa beijou\n\
        a sua sogra, porém Rute se apegou a ela.\n\
        Por isso disse Noemi: Eis que voltou tua cunhada ao seu povo e aos\n\
        seus deuses; volta tu também após tua cunhada.\n\
        Disse, porém, Rute: Não me instes para que te abandone, e deixe de\n\
        seguir-te; porque aonde quer que tu fores irei eu, e onde quer que\n\
        pousares, ali pousarei eu; o teu povo é o meu povo, o teu Deus é o\n\
        meu Deus;\n\
\n\
                         Rute 1:14-16",

/**
 * 1 Samuel
 */
// 035
"        Por este menino orava eu; e o Senhor atendeu à minha petição,\n\
        que eu lhe tinha feito.\n\
\n\
                         1 Samuel 1:27",
// 036
"        O Senhor é o que tira a vida e a dá; faz descer à sepultura\n\
        e faz tornar a subir dela.\n\
\n\
                         1 Samuel 2:6",
// 037
"        Pecando homem contra homem, os juízes o julgarão; pecando,\n\
        porém, o homem contra o Senhor, quem rogará por ele? Mas não\n\
        ouviram a voz de seu pai, porque o Senhor os queria matar.\n\
\n\
                         1 Samuel 2:25",

/**
 * 2 Samuel
 */
// 038
"        E, chegando à eira de Nacom, estendeu Uzá a mão à arca de Deus,\n\
        e pegou nela; porque os bois a deixavam pender.\n\
        Então a ira do Senhor se acendeu contra Uzá, e Deus o feriu ali\n\
        por esta imprudência; e morreu ali junto à arca de Deus.\n\
\n\
                         2 Samuel 6:6, 7",

/**
 * 1 Kings
 */
// 039
"        Porque sucedeu que, no tempo da velhice de Salomão, suas mulheres\n\
        lhe perverteram o coração para seguir outros deuses; e o seu coração\n\
        não era perfeito para com o Senhor seu Deus, como o coração de Davi,\n\
        seu pai,\n\
\n\
                         1 Reis 11:4",
// 040
"        Sucedeu que, no momento de ser oferecido o sacrifício da tarde,\n\
        o profeta Elias se aproximou, e disse: Ó Senhor Deus de Abraão,\n\
        de Isaque e de Israel, manifeste-se hoje que tu és Deus em Israel,\n\
        e que eu sou teu servo, e que conforme à tua palavra fiz todas estas\n\
        coisas.\n\
        Responde-me, Senhor, responde-me, para que este povo conheça que tu\n\
        és o Senhor Deus, e que tu fizeste voltar o seu coração.\n\
\n\
                         1 Reis 18:36, 37",

/**
 * 2 Kings
 */
// 041
"        E ela disse a seu marido: Eis que tenho observado que este\n\
        que sempre passa por nós é um santo homem de Deus.\n\
\n\
                         2 Reis 4:9",

/**
 * 1 Chronicles
 */
// 042
"        Porque grande é o Senhor, e mui digno de louvor, e mais temível\n\
        é do que todos os deuses.\n\
        Porque todos os deuses dos povos são ídolos; porém o Senhor fez\n\
        os céus.\n\
\n\
                         1 Crônicas 16:25,26",

/**
 * 2 Chronicles
 */
// 043
"        Sucedeu que, ouvindo o rei as palavras da lei, rasgou as suas vestes.\n\
\n\
                         2 Crônicas 34:19",

/**
 * Ezra
 */
// 044
"        Porque Esdras tinha preparado o seu coração para buscar a lei do Senhor\n\
        e para cumpri-la e para ensinar em Israel os seus estatutos e os seus juízos.\n\
\n\
                         Esdras 7:10",

/**
 * Nehemiah
 */
// 045 
"        E que não daríamos as nossas filhas aos povos da terra, nem tomaríamos\n\
        as filhas deles para os nossos filhos.\n\
\n\
                         Neemias 10:30",

/**
 * Esther
 */
// 046
"        Vai, ajunta a todos os judeus que se acharem em Susã, e jejuai por mim,\n\
        e não comais nem bebais por três dias, nem de dia nem de noite, e eu e as\n\
        minhas servas também assim jejuaremos. E assim irei ter com o rei, ainda\n\
        que não seja segundo a lei; e se perecer, pereci.\n\
\n\
                         Ester 4:16",

/**
 * Job
 */
// 047
"        Havia um homem na terra de Uz, cujo nome era Jó; e era este homem íntegro,\n\
        reto e temente a Deus e desviava-se do mal.\n\
\n\
                         Jó 1:1",

/**
 * Psalms
 */
// 048
"        Bem-aventurado o homem que não anda segundo o conselho dos ímpios, nem se\n\
        detém no caminho dos pecadores, nem se assenta na roda dos escarnecedores.\n\
\n\
                         Salmos 1:1",

/**
 * Proverbs
 */
// 049
"        O que não faz uso da vara odeia seu filho, mas o que o ama, desde cedo o castiga.\n\
\n\
                         Provérbios 13:24",

/**
 * Ecclesiates
 */
// 050
"        Lembra-te também do teu Criador nos dias da tua mocidade, antes que venham\n\
        os maus dias, e cheguem os anos dos quais venhas a dizer: Não tenho neles\n\
        contentamento;\n\
\n\
                         Eclesiastes 12:1",

/**
 * Song of Solomon
 */
// 051
"        As muitas águas não podem apagar este amor, nem os rios afogá-lo; ainda que alguém\n\
        desse todos os bens de sua casa pelo amor, certamente o desprezariam.\n\
\n\
                         Cânticos 8:7",

/**
 * Isaiah
 */
// 052
"        E clamavam uns aos outros, dizendo: Santo, Santo, Santo é o Senhor dos Exércitos;\n\
        toda a terra está cheia da sua glória.\n\
\n\
                         Isaías 6:3",

/**
 * Jeremiah
 */
// 053
"        Antes que te formasse no ventre te conheci, e antes que saísses da madre, te\n\
        santifiquei; às nações te dei por profeta.\n\
        Então disse eu: Ah, Senhor DEUS! Eis que não sei falar; porque ainda sou um menino.\n\
        Mas o Senhor me disse: Não digas: Eu sou um menino; porque a todos a quem eu te enviar,\n\
        irás; e tudo quanto te mandar, falarás.\n\
\n\
                         Jeremias 1:5-7",

/**
 * Lamentations
 */
// 
"",

/**
 * Ezekiel
 */
// 
"        Assim diz o Senhor DEUS: Ai dos profetas loucos, que seguem o seu próprio espírito\n\
        e que nada viram!\n\
\n\
                         Ezequiel 13:3",

/**
 * Daniel
 */
// 
"       E ele muda os tempos e as estações; ele remove os reis e estabelece os reis; ele dá\n\
       sabedoria aos sábios e conhecimento aos entendidos.\n\
\n\
                         Daniel 2:21",

/**
 * Hosea
 */
// 
"      Escrevi-lhe as grandezas da minha lei, porém essas são estimadas como coisa estranha.\n\
\n\
                         Oséias 8:12",

/**
 * Joel
 */
// 
"      E há de ser que, depois derramarei o meu Espírito sobre toda a carne, e vossos filhos e\n\
      vossas filhas profetizarão, os vossos velhos terão sonhos, os vossos jovens terão visões.\n\
      E também sobre os servos e sobre as servas naqueles dias derramarei o meu Espírito.\n\
\n\
                          Joel 2:28, 29",

/**
 * Amos
 */
// 
"     Eis que vêm dias, diz o Senhor DEUS, em que enviarei fome sobre a terra; não fome de pão,\n\
     nem sede de água, mas de ouvir as palavras do SENHOR.\n\
     E irão errantes de um mar até outro mar, e do norte até ao oriente; correrão por toda a parte,\n\
     buscando a palavra do Senhor, mas não a acharão.\n\
\n\
                         Amós 8:11, 12",

/**
 * Obadiah
 */
// 
"",

/**
 * Jonah
 */
// 
"",

/**
 * Micah
 */
// 
"",

/**
 * Nahum
 */
// 
"",

/**
 * Habakkuk
 */
// 
"",

/**
 * Zephaniah
 */
// 
"",

/**
 * Haggai
 */
// 
"",

/**
 * Zechariah
 */
// 
"     Porque os ídolos têm falado vaidade, e os adivinhos têm visto mentira, e contam sonhos falsos;\n\
     com vaidade consolam, por isso seguem o seu caminho como ovelhas; estão aflitos, porque não há pastor.\n\
\n\
                         Zacarias 10:2",

/**
 * Malachi
 */
// 
"",

/******************************************************************************
 *                                                                            *
 *                                NEW TESTMENT                                *
 *                                                                            *
 ******************************************************************************/

/**
 * Matthew
 */
// 
"",

/**
 * Mark
 */
// 
"",

/**
 * Luke
 */
// 
"",

/**
 * John
 */
// 
"        No princípio era o Verbo, e o Verbo estava com Deus, e o Verbo\n\
        era Deus.\n\
\n\
                             João 1:1",
// 
"        Porque Deus amou o mundo de tal maneira que deu o seu Filho\n\
        unigênito, para que todo aquele que nele crê não pereça,\n\
        mas tenha a vida eterna.\n\
\n\
                             João 3:16"

/**
 * Acts
 */
// 
"",

/**
 * Romans
 */
// 
"",

/**
 * 1 Corinthians
 */
// 
"",

/**
 * 2 Corinthians
 */
// 
"",

/**
 * Galatians
 */
// 
"",

/**
 * Ephesians
 */
// 
"",

/**
 * Philippians
 */
// 
"",

/**
 * Colossians
 */
// 
"",

/**
 * 1 Thessalonians
 */
// 
"",

/**
 * 2 Thessalonians
 */
// 
"",

/**
 * 1 Timothy
 */
// 
"",

/**
 * 2 Timothy
 */
// 
"",

/**
 * Titus
 */
// 
"",

/**
 * Philemon
 */
// 
"",

/**
 * Hebrews
 */
// 
"",

/**
 * James
 */
// 
"",

/**
 * 1 Peter
 */
// 
"",

/**
 * 2 Peter
 */
// 
"",

/**
 * 1 John
 */
// 
"",

/**
 * 2 John
 */
// 
"",

/**
 * 3 John
 */
// 
"",

/**
 * Jude
 */
// 
"",

/**
 * Revelation
 */
// 
"",

NULL
};

void vPrintUsage(void)
{
  int ii = 0;
  
  printf(_("Usage %s [options] <arguments>\n\n"
         "%s\n\n"
         "Options:\n"), gkpszProgramName, DESCRIPTION);
  while(astCmdOpt[ii].name)
  {
    if(astCmdOpt[ii].has_arg == required_argument)
    {
      printf(_("  --%s=<%s>, -%c <%s>\n"
             "    %s\n\n"), astCmdOpt[ii].name, pszCmdArguments[ii],
                            astCmdOpt[ii].val, pszCmdArguments[ii],
                            pszCmdMessages[ii]);
    }
    else
    {
      printf(_("  --%s, -%c\n"
             "    %s\n\n"), astCmdOpt[ii].name, astCmdOpt[ii].val,
                            pszCmdMessages[ii]);
    }

    ii++;
  }
}

void vPrintVersion(void)
{
  printf(_("%s %s\n"
         "Build in %s %s\n"
         "%s %s\n"
         "For reporting bugs, send a email to <%s>\n"), gkpszProgramName, 
                                                        VERSION,
                                                        __DATE__,
                                                        __TIME__,
                                                        COPYRIGHT,
                                                        DEVELOPER,
                                                        DEV_MAIL
  );
}

void vPrintErrorMessage(const char *kpszFmt, ...)
{
  va_list args;
  char szMsg[256];
  
  memset(szMsg, 0, sizeof(szMsg));
   
  va_start(args, kpszFmt);
  
  /**
   * Check if the terminal suport colors
   */
  if(bTerminalSupportColors() == false)
  {
    sprintf(szMsg, _("E: %s\n"), kpszFmt);

    vfprintf(stderr, szMsg, args);
    return;
  }
  
  sprintf(szMsg, _("\033[1;31mE:\033[m %s\n"), kpszFmt);
  
  vfprintf(stderr, szMsg, args);

  va_end(args);
}

bool bCommandLineIsOK(int argc, char **argv)
{
  int iCmdLineOpt = 0;
  
  /**
   * Used to get the final of
   * conversion of strtol
   */
  char *pchEndPtr; 

  while((iCmdLineOpt = getopt_long(argc, argv, kszOptStr, astCmdOpt, NULL )) != -1)
  {
    switch(iCmdLineOpt)
    {
      case 'h':
        vPrintUsage();
        exit(EXIT_SUCCESS);
      case 'v':
        vPrintVersion();
        exit(EXIT_SUCCESS);
      case 't':
        snprintf(gstCmdLine.szLogFileName, sizeof(gstCmdLine.szLogFileName), "%s", optarg);
        break;
      case 'd':
        snprintf(gstCmdLine.szDebugLevel, sizeof(gstCmdLine.szDebugLevel), "%s", optarg);

        strtol(gstCmdLine.szDebugLevel, &pchEndPtr, 10);

        if(*pchEndPtr != '\0')
        {
          return false;
        }

        break;
      case 'c':
        vSetColoredLogLevel(true);

        break;
      case 'C':
        snprintf(gstCmdLine.szConfFileName, sizeof(gstCmdLine.szConfFileName), "%s", optarg);
        break;
      case 'l':
        snprintf(gstCmdLine.szLanguage, sizeof(gstCmdLine.szLanguage), "%s", optarg);
        break;
      case '?':
      default:
        return false;
    }
  }

  return true;
}

void vTraceCommandLine(int argc, char **argv)
{
  int ii;

  vTraceInfo(_("%s - begin"), __func__);

  vTraceAll("argc == %d", argc);

  for(ii = 0; ii < argc; ii++)
  {
    vTraceAll("0x%08lX argv[%d] == %s", (long) &argv[ii], ii, argv[ii]);
  }

  vTraceInfo(_("%s - end"), __func__);
}

void vTraceEnvp(char **envp)
{
  int ii;

  vTraceInfo(_("%s - begin"), __func__);

  if(envp != NULL)
  {
    for(ii = 0; envp[ii] != 0; ii++)
    {
      vTraceAll("0x%08lX envp[%d] == %s", (long) &envp[ii], ii, envp[ii]);
    }
  }

  vTraceInfo(_("%s - end"), __func__);
}

char *szGetProgramName(const char *szPathName)
{
  char *pszProgramName = 0;
  
  if((pszProgramName = strrchr(szPathName, '/')) != 0)
  {
    ++pszProgramName; /* Skip '/' */
  }
  else
  {
    pszProgramName = (char *) szPathName; /* Nenhum dir. component */
  }

  return pszProgramName;
}

void vTraceSystemInfo(void)
{
  /**
   * Date and time information
   */
  time_t tCurrentDateTime;
  struct tm *pstDateTime;
  
  /**
   * Operating System information
   */
  struct utsname stSysInfo;
  
  /**
   * User system info
   */
  struct passwd *pstUserInfo = getpwuid(getuid());

  time(&tCurrentDateTime);
  pstDateTime = localtime(&tCurrentDateTime);

  vTraceInfo(_("%s - begin"), __func__);
 
  if(uname(&stSysInfo) != 0)
  {
    vTraceWarning(_("E: uname(&stSysInfo) != 0"));
  }

  if(pstUserInfo == NULL)
  {
    vTraceWarning(_("pstUserInfo == NULL"));
  }
  
  vTraceAll(_(" GETTING SYSTEM INFORMATION"));
  vTraceAll(_("----------------------------"));
  
  vTraceAll("Current date and time:"
      " %02d/%02d/%04d %02d:%02d:%02d", pstDateTime->tm_mday,
                                        pstDateTime->tm_mon + 1,
                                        pstDateTime->tm_year + 1900,
                                        pstDateTime->tm_hour,
                                        pstDateTime->tm_min,
                                        pstDateTime->tm_sec
  );
  
  vTraceAll(_(" OPERATING SYSTEM INFORMATION"));
  vTraceAll(_("------------------------------"));
  vTraceAll(_("Operating Systen........: %s"), stSysInfo.sysname);
  vTraceAll(_("Host Name...............: %s"), stSysInfo.nodename);
  vTraceAll(_("Kernel Version..........: %s"), stSysInfo.release);
  vTraceAll(_("Operation System Version: %s"), stSysInfo.version);
  vTraceAll(_("Architecture............: %s"), stSysInfo.machine);
  vTraceAll(_("------------------------------"));

  vTraceAll(_(" USER SYSTEM INFORMATION"));
  vTraceAll(_("-------------------------"));
  vTraceAll(_("UID.....................: %u"), pstUserInfo->pw_uid);
  vTraceAll(_("GID.....................: %u"), pstUserInfo->pw_gid);
  vTraceAll(_("User Name...............: %s"), pstUserInfo->pw_name);
  vTraceAll(_("Full Name...............: %s"), pstUserInfo->pw_gecos);
  vTraceAll(_("Home Directory..........: %s"), pstUserInfo->pw_dir);
  vTraceAll(_("Default Shell...........: %s"), pstUserInfo->pw_shell);
  vTraceAll(_("-------------------------"));
  
  vTraceInfo(_("%s - end"), __func__);
}

void vTraceProgramInfo(void)
{
  vTraceAll(_("%s - begin"), __func__);
  
  vTraceAll(_(" PROGRAM INFORMATION"));
  vTraceAll(_("---------------------"));
  vTraceAll(_("Software..........: %s"),    gkpszProgramName);
  vTraceAll(_("Version...........: %s"),    VERSION);
  vTraceAll(_("Copyright.........: %s"),    COPYRIGHT);
  vTraceAll(_("Configuration file: %s"),    gstCmdLine.szConfFileName);
  vTraceAll(_("Log file..........: %s"),    LOG_FILE_NAME);
  vTraceAll(_("Build in..........: %s %s"), __DATE__, __TIME__);
  vTraceAll(_("Report bugs to....: <%s>"),  DEV_MAIL);
  vTraceAll(_("Github............: %s"),    GITHUB_URL);
  vTraceAll(_("---------------------"));

  vTraceAll(_("%s - end"), __func__);
}

int iGenerateRandomIndex(void)
{
  int iRandom;

  if(INFO_DETAILS) vTraceInfo("%s - begin", __func__);

  srand(time(NULL));
  
  iRandom = rand() % QTY_VERSICLES;
  
  if(INFO_DETAILS) vTraceInfo("%s - end iRandom = %d", __func__, iRandom);

  return iRandom;
}

void vPrintEN_BiblicalText(int iIndex)
{
  if(INFO_DETAILS) vTraceInfo("%s - begin", __func__);

  puts(gkpszEN_BiblicalTexts[iIndex]);
  
  if(INFO_DETAILS)
  {
    vTraceInfo("%s", gkpszEN_BiblicalTexts[iIndex]);
    vTraceInfo("%s - end", __func__);
  }
}

void vPrintBR_BiblicalText(int iIndex)
{
  if(INFO_DETAILS) vTraceInfo("%s - begin", __func__);

  puts(gkpszBR_BiblicalTexts[iIndex]);
  
  if(INFO_DETAILS)
  {
    vTraceInfo("%s", gkpszBR_BiblicalTexts[iIndex]);
    vTraceInfo("%s - end", __func__);
  }
}

void vReadConfFile(void)
{
  FILE *pfConfFile;
  char szLine[2048];
  int iLineLen = sizeof(szLine);
  char *pTok = NULL;
  int ii = 0;
  bool bFoundLang = false;
  
  memset(szLine, 0, iLineLen);

  if(INFO_DETAILS) vTraceInfo("%s - begin", __func__);

  if(!bOpenFile(&pfConfFile, gstCmdLine.szConfFileName, "r"))
  {
    vPrintErrorMessage("Impossible open the file %s", gstCmdLine.szConfFileName);
    exit(EXIT_FAILURE);
  }
  
  while(fgets(szLine, iLineLen, pfConfFile))
  {
    if(DEBUG_DETAILS) vTraceDebug("szLine = [%s]", szLine);

    /**
     * Skip comments
     */
    if(szLine[0] == '#') continue;
    
    pTok = strtok(szLine, " =\n#");
    
    if(DEBUG_DETAILS) vTraceDebug("1 pTok = [%s]", pTok);

    if(strstr(szLine, "LANG") && bStrIsEmpty(gstCmdLine.szLanguage))
    {
      bFoundLang = true;
      
      while(pTok != NULL)
      {
        if(ii == 1)
        {
          if(DEBUG_DETAILS) vTraceDebug("ii = %d", ii);

          if(bStrIsEmpty(pTok))
          {
            vPrintErrorMessage("LANG is empty in file %s!", gstCmdLine.szConfFileName);

            if(!bCloseFile(&pfConfFile))
            {
              vPrintErrorMessage("Impossible close the file %s", gstCmdLine.szConfFileName);
              exit(EXIT_FAILURE);
            }
          }
          
          if(DEBUG_DETAILS) vTraceDebug("pTok is not empty");

          sprintf(gstCmdLine.szLanguage, "%s", pTok);
          
          if(DEBUG_DETAILS)
          {
            vTraceDebug("pTok = [%s]", pTok);
            vTraceDebug("gstCmdLine.szLanguage = [%s]", gstCmdLine.szLanguage);
          }
          
          break;
        }

        pTok = strtok(NULL, " =\n#");

        if(DEBUG_DETAILS) vTraceDebug("2 pTok = [%s]", pTok);

        ii++;
      }

      break;
    }
    else
    {
      continue;
    }
  }
  
  if(!bFoundLang)
  {
    vPrintErrorMessage("LANG not found in %s file!", gstCmdLine.szConfFileName);
    if(FATAL_DETAILS) vTraceFatal("LANG not found in %s file!", gstCmdLine.szConfFileName);
  }

  if(INFO_DETAILS) vTraceInfo("bFound == true");
  
  if(!bCloseFile(&pfConfFile))
  {
    if(FATAL_DETAILS) vTraceFatal("Impossible close the file %s", gstCmdLine.szConfFileName);
    if(INFO_DETAILS) vTraceInfo("%s  - end", __func__);
    exit(EXIT_FAILURE);
  }

  if(INFO_DETAILS) vTraceInfo("%s  - end", __func__);
}

void vPrintBiblicalText(void)
{
  int iIndex = iGenerateRandomIndex();
  
  if(INFO_DETAILS) vTraceInfo("%s - begin", __func__);
  if(DEBUG_DETAILS) vTraceDebug("gstCmdLine.szLanguage = [%s]", gstCmdLine.szLanguage);

  if(!strcmp(gstCmdLine.szLanguage, "ptBR"))
  {
    vPrintBR_BiblicalText(iIndex);
  }
  else if(!strcmp(gstCmdLine.szLanguage, "enUS"))
  {
    vPrintEN_BiblicalText(iIndex);
  }
  else
  {
    vPrintErrorMessage("Invalid language!");
    printf("%s supports only ptBR and enUS\n", gkpszProgramName);
  }

  if(INFO_DETAILS) vTraceInfo("%s - end", __func__);
}
/******************************************************************************
 *                                                                            *
 *                                   main                                     *
 *                                                                            *
 ******************************************************************************/
#ifdef __linux__
int main(int argc, char **argv, char **envp)
#else
int main(int argc, char **argv)
#endif /* __linux__ */
{
  int iRsl = 0;
  
  memset(&gstCmdLine, 0, sizeof(gstCmdLine));

  /* Setting the name of program */
  gkpszProgramName = szGetProgramName(argv[0]);
  
  UNUSED(kszLogLevelColorInit);
  UNUSED(kszLogLevelColorEnd);
  UNUSED(kszLogLevel);
  UNUSED(kszBoldColors);
  UNUSED(kszNormalColors);
  
  setlocale(LC_ALL, NULL);
  
  bindtextdomain(gkpszProgramName, LOCALE_DIR);
  textdomain(gkpszProgramName);
  
  /* Checking and validate the command line arguments */
  if(!bCommandLineIsOK(argc, argv))
  {
    vPrintUsage();
    exit(EXIT_FAILURE);
  }

  /* .conf file  */
  if(!bStrIsEmpty(gstCmdLine.szConfFileName))
  {
    vSetConfFileName(gstCmdLine.szConfFileName);
  }
  else
  {
    sprintf(gstCmdLine.szConfFileName, "%s/.%s", getenv("HOME"), CONF_FILE_NAME);
  
    if(!bFileExist(gstCmdLine.szConfFileName))
    {
      sprintf(gstCmdLine.szConfFileName, "/etc/%s", CONF_FILE_NAME);
    }
    
    if(!bFileExist(gstCmdLine.szConfFileName))
    {
      sprintf(gstCmdLine.szConfFileName, "./%s", CONF_FILE_NAME);
    }
    
    if(!bFileExist(gstCmdLine.szConfFileName))
    {
      exit(EXIT_FAILURE);
    }

    vSetConfFileName(gstCmdLine.szConfFileName);
  }

  /* DebugLevel configurations */
  if(!bStrIsEmpty(gstCmdLine.szDebugLevel)) 
  {
    vSetLogLevel(atoi(gstCmdLine.szDebugLevel));
  }
  else 
  {
    vSetLogLevel(iGetLogLevel());
  }
#if 0
  if(giDebugLevel < 0)
  {
    vPrintErrorMessage(_("Debug Level it's less than 0!"));

    exit(EXIT_FAILURE);
  }
#endif
  if(!bStrIsEmpty(gstCmdLine.szLogFileName))
  {
    vSetLogFileName(gstCmdLine.szLogFileName);
  }
  else
  {
#if 0
    sprintf(gstCmdLine.szLogFileName, "/var/%s", LOG_FILE_NAME);
  
    vSetLogFileName(gstCmdLine.szLogFileName);
#endif
    vSetLogFileName(LOG_FILE_NAME);
  }
  
  if(bStrIsEmpty(gstCmdLine.szLanguage))
  {
    sprintf(gstCmdLine.szLanguage, "enUS");
  }

  if(INFO_DETAILS)
  {
    vTraceInfo(_("%s - begin"), __func__);
  }

  if(TRACE_DETAILS)
  {
    vTraceCommandLine(argc, argv);
    vTraceProgramInfo();
    vTraceSystemInfo();
    vTraceEnvp(envp);
  }
  
  vReadConfFile();

  vPrintBiblicalText();

  if(INFO_DETAILS)
  {
    vTraceInfo(_("%s end iRsl == %d"), __func__, iRsl);
  }

  return iRsl;
}

