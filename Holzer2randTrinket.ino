// Jenny Holzer Truisms: https://www.cs.utexas.edu/~field/holzer/truisms.txt
// Based on example code from https://github.com/MajicDesigns/MD_Parola
// MD_MAX72XX library can be found at https://github.com/MajicDesigns/MD_MAX72XX
//

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <avr/pgmspace.h>
#include <Adafruit_DotStar.h> // turn off Trinket onboard DotStar LED

// 

const char string_1[] PROGMEM = "A little knowledge can go a long way";
const char string_2[] PROGMEM = "A lot of professionals are crackpots";
const char string_3[] PROGMEM = "A man can't know what it is to be a mother";
const char string_4[] PROGMEM = "A name means a lot just by itself";
const char string_5[] PROGMEM = "A positive attitude means all the difference in the world";
const char string_6[] PROGMEM = "A relaxed man is not necessarily a better man";
const char string_7[] PROGMEM = "A sense of timing is the mark of genius";
const char string_8[] PROGMEM = "A sincere effort is all you can ask";
const char string_9[] PROGMEM = "A single event can have infinitely many interpretations";
const char string_10[] PROGMEM = "A solid home base builds a sense of self";
const char string_11[] PROGMEM = "A strong sense of duty imprisons you";
const char string_12[] PROGMEM = "Absolute submission can be a form of freedom";
const char string_13[] PROGMEM = "Abstraction is a type of decadence";
const char string_14[] PROGMEM = "Abuse of power comes as no surprise";
const char string_15[] PROGMEM = "Action causes more trouble than thought";
const char string_16[] PROGMEM = "Alienation produces eccentrics or revolutionaries";
const char string_17[] PROGMEM = "All things are delicately interconnected";
const char string_18[] PROGMEM = "Ambition is just as dangerous as complacency";
const char string_19[] PROGMEM = "Ambivalence can ruin your life";
const char string_20[] PROGMEM = "An elite is inevitable";
const char string_21[] PROGMEM = "Anger or hate can be a useful motivating force";
const char string_22[] PROGMEM = "Animalism is perfectly healthy";
const char string_23[] PROGMEM = "Any surplus is immoral";
const char string_24[] PROGMEM = "Anything is a legitimate area of investigation";
const char string_25[] PROGMEM = "Artificial desires are despoiling the earth";
const char string_26[] PROGMEM = "At times inactivity is preferable to mindless functioning";
const char string_27[] PROGMEM = "At times your unconsciousness is truer than your conscious mind";
const char string_28[] PROGMEM = "Automation is deadly";
const char string_29[] PROGMEM = "Awful punishment awaits really bad people";
const char string_30[] PROGMEM = "Bad intentions can yield good results";
const char string_31[] PROGMEM = "Being alone with yourself is increasingly unpopular";
const char string_32[] PROGMEM = "Being happy is more important than anything else";
const char string_33[] PROGMEM = "Being judgmental is a sign of life";
const char string_34[] PROGMEM = "Being sure of yourself means you're a fool";
const char string_35[] PROGMEM = "Believing in rebirth is the same as admitting defeat";
const char string_36[] PROGMEM = "Boredom makes you do crazy things";
const char string_37[] PROGMEM = "Calm is more conductive to creativity than is anxiety";
const char string_38[] PROGMEM = "Categorizing fear is calming";
const char string_39[] PROGMEM = "Change is valuable when the oppressed become tyrants";
const char string_40[] PROGMEM = "Chasing the new is dangerous to society";
const char string_41[] PROGMEM = "Children are the most cruel of all";
const char string_42[] PROGMEM = "Children are the hope of the future";
const char string_43[] PROGMEM = "Class action is a nice idea with no substance";
const char string_44[] PROGMEM = "Class structure is as artificial as plastic";
const char string_45[] PROGMEM = "Confusing yourself is a way to stay honest";
const char string_46[] PROGMEM = "Crime against property is relatively unimportant";
const char string_47[] PROGMEM = "Decadence can be an end in itself";
const char string_48[] PROGMEM = "Decency is a relative thing";
const char string_49[] PROGMEM = "Dependence can be a meal ticket";
const char string_50[] PROGMEM = "Description is more important than metaphor";
const char string_51[] PROGMEM = "Deviants are sacrificed to increase group solidarity";
const char string_52[] PROGMEM = "Disgust is the appropriate response to most situations";
const char string_53[] PROGMEM = "Disorganization is a kind of anesthesia";
const char string_54[] PROGMEM = "Don't place to much trust in experts";
const char string_55[] PROGMEM = "Drama often obscures the real issues";
const char string_56[] PROGMEM = "Dreaming while awake is a frightening contradiction";
const char string_57[] PROGMEM = "Dying and coming back gives you considerable perspective";
const char string_58[] PROGMEM = "Dying should be as easy as falling off a log";
const char string_59[] PROGMEM = "Eating too much is criminal";
const char string_60[] PROGMEM = "Elaboration is a form of pollution";
const char string_61[] PROGMEM = "Emotional responses ar as valuable as intellectual responses";
const char string_62[] PROGMEM = "Enjoy yourself because you can't change anything anyway";
const char string_63[] PROGMEM = "Ensure that your life stays in flux";
const char string_64[] PROGMEM = "Even your family can betray you";
const char string_65[] PROGMEM = "Every achievement requires a sacrifice";
const char string_66[] PROGMEM = "Everyone's work is equally important";
const char string_67[] PROGMEM = "Everything that's interesting is new";
const char string_68[] PROGMEM = "Exceptional people deserve special concessions";
const char string_69[] PROGMEM = "Expiring for love is beautiful but stupid";
const char string_70[] PROGMEM = "Expressing anger is necessary";
const char string_71[] PROGMEM = "Extreme behavior has its basis in pathological psychology";
const char string_72[] PROGMEM = "Extreme self-consciousness leads to perversion";
const char string_73[] PROGMEM = "Faithfulness is a social not a biological law";
const char string_74[] PROGMEM = "Fake or real indifference is a powerful personal weapon";
const char string_75[] PROGMEM = "Fathers often use too much force";
const char string_76[] PROGMEM = "Fear is the greatest incapacitator";
const char string_77[] PROGMEM = "Freedom is a luxury not a necessity";
const char string_78[] PROGMEM = "Giving free rein to your emotions is an honest way to live";
const char string_79[] PROGMEM = "Go all out in romance and let the chips fall where they may";
const char string_80[] PROGMEM = "Going with the flow is soothing but risky";
const char string_81[] PROGMEM = "Good deeds eventually are rewarded";
const char string_82[] PROGMEM = "Government is a burden on the people";
const char string_83[] PROGMEM = "Grass roots agitation is the only hope";
const char string_84[] PROGMEM = "Guilt and self-laceration are indulgences";
const char string_85[] PROGMEM = "Habitual contempt doesn't reflect a finer sensibility";
const char string_86[] PROGMEM = "Hiding your emotions is despicable";
const char string_87[] PROGMEM = "Holding back protects your vital energies";
const char string_88[] PROGMEM = "Humanism is obsolete";
const char string_89[] PROGMEM = "Humor is a release";
const char string_90[] PROGMEM = "Ideals are replaced by conventional goals at a certain age";
const char string_91[] PROGMEM = "If you aren't political your personal life should be exemplary";
const char string_92[] PROGMEM = "If you can't leave your mark give up";
const char string_93[] PROGMEM = "If you have many desires your life will be interesting";
const char string_94[] PROGMEM = "If you live simply there is nothing to worry about";
const char string_95[] PROGMEM = "Ignoring enemies is the best way to fight";
const char string_96[] PROGMEM = "Illness is a state of mind";
const char string_97[] PROGMEM = "Imposing order is man's vocation for chaos is hell";
const char string_98[] PROGMEM = "In some instances it's better to die than to continue";
const char string_99[] PROGMEM = "Inheritance must be abolished";
const char string_100[] PROGMEM = "It can be helpful to keep going no matter what";
const char string_101[] PROGMEM = "It is heroic to try to stop time";
const char string_102[] PROGMEM = "It is man's fate to outsmart himself";
const char string_103[] PROGMEM = "It is a gift to the world not to have babies";
const char string_104[] PROGMEM = "It's better to be a good person than a famous person";
const char string_105[] PROGMEM = "It's better to be lonely than to be with inferior people";
const char string_106[] PROGMEM = "It's better to be naive than jaded";
const char string_107[] PROGMEM = "It's better to study the living fact than to analyze history";
const char string_108[] PROGMEM = "It's crucial to have an active fantasy life";
const char string_109[] PROGMEM = "It's good to give extra money to charity";
const char string_110[] PROGMEM = "It's important to stay clean on all levels";
const char string_111[] PROGMEM = "It's just an accident that your parents are your parents";
const char string_112[] PROGMEM = "It's not good to hold too many absolutes";
const char string_113[] PROGMEM = "It's not good to operate on credit";
const char string_114[] PROGMEM = "It's vital to live in harmony with nature";
const char string_115[] PROGMEM = "Just believing something can make it happen";
const char string_116[] PROGMEM = "Keep something in reserve for emergencies";
const char string_117[] PROGMEM = "Killing is unavoidable but nothing to be proud of";
const char string_118[] PROGMEM = "Knowing yourself lets you understand others";
const char string_119[] PROGMEM = "Knowledge should be advanced at all costs";
const char string_120[] PROGMEM = "Labor is a life-destroying activity";
const char string_121[] PROGMEM = "Lack of charisma can be fatal";
const char string_122[] PROGMEM = "Leisure time is a gigantic smoke screen";
const char string_123[] PROGMEM = "Listen when your body talks";
const char string_124[] PROGMEM = "Looking back is the first sign of aging and decay";
const char string_125[] PROGMEM = "Loving animals is a substitute activity";
const char string_126[] PROGMEM = "Low expectations are good protection";
const char string_127[] PROGMEM = "Manual labor can be refreshing and wholesome";
const char string_128[] PROGMEM = "Men are not monogamous by nature";
const char string_129[] PROGMEM = "Moderation kills the spirit";
const char string_130[] PROGMEM = "Money creates taste";
const char string_131[] PROGMEM = "Monomania is a prerequisite of success";
const char string_132[] PROGMEM = "Morals are for little people";
const char string_133[] PROGMEM = "Most people are not fit to rule themselves";
const char string_134[] PROGMEM = "Mostly you should mind your own business";
const char string_135[] PROGMEM = "Mothers shouldn't make too many sacrifices";
const char string_136[] PROGMEM = "Much was decided before you were born";
const char string_137[] PROGMEM = "Murder has its sexual side";
const char string_138[] PROGMEM = "Myth can make reality more intelligible";
const char string_139[] PROGMEM = "Noise can be hostile";
const char string_140[] PROGMEM = "Nothing upsets the balance of good and evil";
const char string_141[] PROGMEM = "Occasionally principles are more valuable than people";
const char string_142[] PROGMEM = "Offer very little information about yourself";
const char string_143[] PROGMEM = "Often you should act like you are sexless";
const char string_144[] PROGMEM = "Old friends are better left in the past";
const char string_145[] PROGMEM = "Opacity is an irresistible challenge";
const char string_146[] PROGMEM = "Pain can be a very positive thing";
const char string_147[] PROGMEM = "People are boring unless they are extremists";
const char string_148[] PROGMEM = "People are nuts if they think they are important";
const char string_149[] PROGMEM = "People are responsible for what they do unless they are insane";
const char string_150[] PROGMEM = "People who don't work with their hands are parasites";
const char string_151[] PROGMEM = "People who go crazy are too sensitive";
const char string_152[] PROGMEM = "People won't behave if they have nothing to lose";
const char string_153[] PROGMEM = "Physical culture is second best";
const char string_154[] PROGMEM = "Planning for the future is escapism";
const char string_155[] PROGMEM = "Playing it safe can cause a lot of damage in the long run";
const char string_156[] PROGMEM = "Politics is used for personal gain";
const char string_157[] PROGMEM = "Potential counts for nothing until it's realized";
const char string_158[] PROGMEM = "Private property created crime";
const char string_159[] PROGMEM = "Pursuing pleasure for the sake of pleasure will ruin you";
const char string_160[] PROGMEM = "Push yourself to the limit as often as possible";
const char string_161[] PROGMEM = "Raise boys and girls the same way";
const char string_162[] PROGMEM = "Random mating is good for debunking sex myths";
const char string_163[] PROGMEM = "Rechanneling destructive impulses is a sign of maturity";
const char string_164[] PROGMEM = "Recluses always get weak";
const char string_165[] PROGMEM = "Redistributing wealth is imperative";
const char string_166[] PROGMEM = "Relativity is no boon to mankind";
const char string_167[] PROGMEM = "Religion causes as many problems as it solves";
const char string_168[] PROGMEM = "Remember you always have freedom of choice";
const char string_169[] PROGMEM = "Repetition is the best way to learn";
const char string_170[] PROGMEM = "Resolutions serve to ease our conscience";
const char string_171[] PROGMEM = "Revolution begins with changes in the individual";
const char string_172[] PROGMEM = "Romantic love was invented to manipulate women";
const char string_173[] PROGMEM = "Routine is a link with the past";
const char string_174[] PROGMEM = "Routine small excesses are worse than then the occasional debauch";
const char string_175[] PROGMEM = "Sacrificing yourself for a bad cause is not a moral act";
const char string_176[] PROGMEM = "Salvation can't be bought and sold";
const char string_177[] PROGMEM = "Self-awareness can be crippling";
const char string_178[] PROGMEM = "Self-contempt can do more harm than good";
const char string_179[] PROGMEM = "Selfishness is the most basic motivation";
const char string_180[] PROGMEM = "Selflessness is the highest achievement";
const char string_181[] PROGMEM = "Separatism is the way to a new beginning";
const char string_182[] PROGMEM = "Sex differences are here to stay";
const char string_183[] PROGMEM = "Sin is a means of social control";
const char string_184[] PROGMEM = "Slipping into madness is good for the sake of comparison";
const char string_185[] PROGMEM = "Sloppy thinking gets worse over time";
const char string_186[] PROGMEM = "Solitude is enriching";
const char string_187[] PROGMEM = "Sometimes science advances faster than it should";
const char string_188[] PROGMEM = "Sometimes things seem to happen of their own accord";
const char string_189[] PROGMEM = "Spending too much time on self-improvement is antisocial";
const char string_190[] PROGMEM = "Starvation is nature's way";
const char string_191[] PROGMEM = "Stasis is a dream state";
const char string_192[] PROGMEM = "Sterilization is a weapon of the rulers";
const char string_193[] PROGMEM = "Strong emotional attachment stems from basic insecurity";
const char string_194[] PROGMEM = "Stupid people shouldn't breed";
const char string_195[] PROGMEM = "Survival of the fittest applies to men and animals";
const char string_196[] PROGMEM = "Symbols are more meaningful than things themselves";
const char string_197[] PROGMEM = "Taking a strong stand publicizes the opposite position";
const char string_198[] PROGMEM = "Talking is used to hide one's inability to act";
const char string_199[] PROGMEM = "Teasing people sexually can have ugly consequences";
const char string_200[] PROGMEM = "Technology will make or break us";
const char string_201[] PROGMEM = "The cruelest disappointment is when you let yourself down";
const char string_202[] PROGMEM = "The desire to reproduce is a death wish";
const char string_203[] PROGMEM = "The family is living on borrowed time";
const char string_204[] PROGMEM = "The idea of revolution is an adolescent fantasy";
const char string_205[] PROGMEM = "The idea of transcendence is used to obscure oppression";
const char string_206[] PROGMEM = "The idiosyncratic has lost its authority";
const char string_207[] PROGMEM = "The most profound things are inexpressible";
const char string_208[] PROGMEM = "The mundane is to be cherished";
const char string_209[] PROGMEM = "The new is nothing but a restatement of the old";
const char string_210[] PROGMEM = "The only way to be pure is to stay by yourself";
const char string_211[] PROGMEM = "The sum of your actions determines what you are";
const char string_212[] PROGMEM = "The unattainable is invariable attractive";
const char string_213[] PROGMEM = "The world operates according to discoverable laws";
const char string_214[] PROGMEM = "There are too few immutable truths today";
const char string_215[] PROGMEM = "There's nothing except what you sense";
const char string_216[] PROGMEM = "There's nothing redeeming in toil";
const char string_217[] PROGMEM = "Thinking too much can only cause problems";
const char string_218[] PROGMEM = "Threatening someone sexually is a horrible act";
const char string_219[] PROGMEM = "Timidity is laughable";
const char string_220[] PROGMEM = "To disagree presupposes moral integrity";
const char string_221[] PROGMEM = "To volunteer is reactionary";
const char string_222[] PROGMEM = "Torture is barbaric";
const char string_223[] PROGMEM = "Trading a life for a life is fair enough";
const char string_224[] PROGMEM = "True freedom is frightful";
const char string_225[] PROGMEM = "Unique things must be the most valuable";
const char string_226[] PROGMEM = "Unquestioning love demonstrates largesse of spirit";
const char string_227[] PROGMEM = "Using force to stop force is absurd";
const char string_228[] PROGMEM = "Violence is permissible even desirable occasionally";
const char string_229[] PROGMEM = "War is a purification rite";
const char string_230[] PROGMEM = "We must make sacrifices to maintain our quality of life";
const char string_231[] PROGMEM = "When something terrible happens people wake up";
const char string_232[] PROGMEM = "Wishing things away is not effective";
const char string_233[] PROGMEM = "With perseverance you can discover any truth";
const char string_234[] PROGMEM = "Words tend to be inadequate";
const char string_235[] PROGMEM = "Worrying can help you prepare";
const char string_236[] PROGMEM = "You are a victim of the rules you live by";
const char string_237[] PROGMEM = "You are guileless in your dreams";
const char string_238[] PROGMEM = "You are responsible for constituting the meaning of things";
const char string_239[] PROGMEM = "You are the past present and future";
const char string_240[] PROGMEM = "You can live on through your descendants";
const char string_241[] PROGMEM = "You can't expect people to be something they're not";
const char string_242[] PROGMEM = "You can't fool others if you're fooling yourself";
const char string_243[] PROGMEM = "You don't know what's what until you support yourself";
const char string_244[] PROGMEM = "You have to hurt others to be extraordinary";
const char string_245[] PROGMEM = "You must be intimate with a token few";
const char string_246[] PROGMEM = "You must disagree with authority figures";
const char string_247[] PROGMEM = "You must have one grand passion";
const char string_248[] PROGMEM = "You must know where you stop and the world begins";
const char string_249[] PROGMEM = "You can understand someone of your sex only";
const char string_250[] PROGMEM = "You owe the world not the other way around";
const char string_251[] PROGMEM = "You should study as much as possible";
const char string_252[] PROGMEM = "Your actions are pointless if no one notices";
const char string_253[] PROGMEM = "Your oldest fears are the worst ones";


// Set up a table to refer to the strings.

const char * const truisms[] PROGMEM = 
{ string_1, string_2, string_3, string_4, string_5, string_6, string_7, string_8, string_9, string_10,
  string_11, string_12, string_13, string_14, string_15, string_16, string_17, string_18, string_19, string_20,
  string_21, string_22, string_23, string_24, string_25, string_26, string_27, string_28, string_29, string_30,
  string_31, string_32, string_33, string_34, string_35, string_36, string_37, string_38, string_39, string_40,
  string_41, string_42, string_43, string_44, string_45, string_46, string_47, string_48, string_49, string_50,
  string_51, string_52, string_53, string_54, string_55, string_56, string_57, string_58, string_59, string_60,
  string_61, string_62, string_63, string_64, string_65, string_66, string_67, string_68, string_69, string_70, 
  string_71, string_72, string_73, string_74, string_75, string_76, string_77, string_78, string_79, string_80, 
  string_81, string_82, string_83, string_84, string_85, string_86, string_87, string_88, string_89, string_90, 
  string_91, string_92, string_93, string_94, string_95, string_96, string_97, string_98, string_99, string_100, 
  string_101, string_102, string_103, string_104, string_105, string_106, string_107, string_108, string_109, string_110,
  string_111, string_112, string_113, string_114, string_115, string_116, string_117, string_118, string_119, string_120,
  string_121, string_122, string_123, string_124, string_125, string_126, string_127, string_128, string_129, string_130,
  string_131, string_132, string_133, string_134, string_135, string_136, string_137, string_138, string_139, string_140,
  string_141, string_142, string_143, string_144, string_145, string_146, string_147, string_148, string_149, string_150,
  string_151, string_152, string_153, string_154, string_155, string_156, string_157, string_158, string_159, string_160,
  string_161, string_162, string_163, string_164, string_165, string_166, string_167, string_168, string_169, string_170,
  string_171, string_172, string_173, string_174, string_175, string_176, string_177, string_178, string_179, string_180,
  string_181, string_182, string_183, string_184, string_185, string_186, string_187, string_188, string_189, string_190,
  string_191, string_192, string_193, string_194, string_195, string_196, string_197, string_198, string_199, string_200,
  string_201, string_202, string_203, string_204, string_205, string_206, string_207, string_208, string_209, string_210,
  string_211, string_212, string_213, string_214, string_215, string_216, string_217, string_218, string_219, string_220,
  string_221, string_222, string_223, string_224, string_225, string_226, string_227, string_228, string_229, string_230,
  string_231, string_232, string_233, string_234, string_235, string_236, string_237, string_238, string_239, string_240,
  string_241, string_242, string_243, string_244, string_245, string_246, string_247, string_248, string_249, string_250,
  string_251, string_252, string_253
};

int truismNumber[] ={ 83, 48, 250, 18, 162, 27, 122, 103, 190, 85, 168, 62, 13, 200, 215, 238, 97, 51, 29, 45, 115, 236, 22, 150, 37,
                      180, 6, 2, 206, 171, 54, 19, 34, 227, 185, 247, 192, 135, 74, 99, 101, 91, 197, 218, 125, 158, 4, 241, 81, 10,
                      35, 228, 146, 201, 231, 249, 25, 3, 174, 71, 44, 69, 144, 121, 42, 161, 16, 77, 234, 120, 118, 237, 123, 109,
                      229, 57, 132, 112, 126, 152, 108, 104, 39, 189, 253, 175, 93, 88, 110, 90, 52, 28, 24, 128, 116, 203, 140, 205,
                      119, 242, 187, 243, 166, 151, 149, 143, 251, 127, 21, 136, 169, 49, 188, 167, 130, 142, 70, 164, 210, 7, 41, 138,
                      53, 245, 194, 64, 170, 217, 133, 145, 235, 11, 223, 155, 131, 240, 107, 46, 193, 89, 141, 58, 14, 157, 204, 50,
                      43, 213, 78, 230, 72, 114, 61, 56, 202, 224, 96, 153, 207, 12, 9, 195, 183, 17, 106, 1, 163, 55, 221, 124, 225,
                      60, 182, 220, 80, 134, 63, 59, 23, 87, 98, 47, 209, 66, 181, 31, 239, 40, 5, 165, 100, 191, 214, 226, 178, 177,
                      208, 94, 248, 176, 73, 222, 76, 32, 20, 186, 38, 65, 137, 117, 246, 216, 36, 160, 148, 154, 212, 33, 26, 113, 84,
                      172, 244, 86, 233, 196, 198, 199, 75, 82, 79, 139, 102, 92, 179, 95, 111, 8, 105, 129, 147, 156, 68, 232, 159,
                      219, 184, 30, 252, 173, 211, 15, 63
                    };

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 8

//pins for old Arduino
//#define CLK_PIN   13
//#define DATA_PIN  11
//#define CS_PIN    10

//pins for Trinket M0  - works for software SPI, but not hardware.
#define CLK_PIN   2
#define DATA_PIN  0
#define CS_PIN    3

// HARDWARE SPI
// MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// SOFTWARE SPI
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

// Scrolling parameters
uint8_t scrollSpeed = 30;    // default frame delay value
textEffect_t scrollEffect = PA_SCROLL_LEFT;
textPosition_t scrollAlign = PA_LEFT;
//uint16_t scrollPause = 2000; // in milliseconds
uint16_t scrollPause = 0;

// Global message buffer
#define	BUF_SIZE	75
char curMessage[BUF_SIZE] = { "" };

Adafruit_DotStar strip = Adafruit_DotStar(1, INTERNAL_DS_DATA, INTERNAL_DS_CLK, DOTSTAR_BGR);

void setup()
{
  // turn off onboard dotstar
  strip.begin();
  strip.setPixelColor(0, 0, 0, 0); strip.show();

  // Initialize message subsyste
  P.begin();
  P.displayText(curMessage, scrollAlign, scrollSpeed, scrollPause, scrollEffect, scrollEffect);
  randomSeed(analogRead(0));
  
}

void loop()
{
      for (int i = 1; i <= 253; i++) {
        strcpy_P(curMessage, (char*)pgm_read_word(&(truisms[truismNumber[i]])));
        while (!P.displayAnimate()) {};
        P.displayReset();
      }
}
