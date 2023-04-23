//Yêu cầu C++0x Compiler. Chạy chương trình online: http://tpcg.io/7E62Y2

#include <bits/stdc++.h>
using namespace std;

typedef array<pair<char, double>, 26> FreqArray;

class VigenereAnalyser 
{
private:
  array<double, 26> targets;
  array<double, 26> sortedTargets;
  FreqArray freq;

  FreqArray& frequency(const string& input) 
  {
    for (char c = 'A'; c <= 'Z'; ++c)
      freq[c - 'A'] = make_pair(c, 0);

    for (size_t i = 0; i < input.size(); ++i)
      freq[input[i] - 'A'].second++;

    return freq;
  }

  double correlation(const string& input) 
  {
    double result = 0.0;
    frequency(input);

    sort(freq.begin(), freq.end(), [](pair<char, double> u, pair<char, double> v)->bool
      { return u.second < v.second; });

    for (size_t i = 0; i < 26; ++i)
      result += freq[i].second * sortedTargets[i];

    return result;
  }

public:
  VigenereAnalyser(const array<double, 26>& targetFreqs) 
  {
    targets = targetFreqs;
    sortedTargets = targets;
    sort(sortedTargets.begin(), sortedTargets.end());
  }

  pair<string, string> analyze(string input) 
  {
    string cleaned;
    for (size_t i = 0; i < input.size(); ++i) 
    {
      if (input[i] >= 'A' && input[i] <= 'Z')
        cleaned += input[i];
      else if (input[i] >= 'a' && input[i] <= 'z')
        cleaned += input[i] + 'A' - 'a';
    }

    size_t bestLength = 0;
    double bestCorr = -100.0;

    for (size_t i = 2; i < cleaned.size() / 20; ++i) 
    {
      vector<string> pieces(i);
      for (size_t j = 0; j < cleaned.size(); ++j)
        pieces[j % i] += cleaned[j];
        
      double corr = -0.5*i;
      for (size_t j = 0; j < i; ++j)
        corr += correlation(pieces[j]);

      if (corr > bestCorr) 
      {
        bestLength = i;
        bestCorr = corr;
      }
    }

    if (bestLength == 0)
      return make_pair("Text is too short to analyze", "");

    vector<string> pieces(bestLength);
    for (size_t i = 0; i < cleaned.size(); ++i)
      pieces[i % bestLength] += cleaned[i];

    vector<FreqArray> freqs;
    for (size_t i = 0; i < bestLength; ++i)
      freqs.push_back(frequency(pieces[i]));

    string key = "";
    for (size_t i = 0; i < bestLength; ++i) 
    {
      sort(freqs[i].begin(), freqs[i].end(), [](pair<char, double> u, pair<char, double> v)->bool
        { return u.second > v.second; });

      size_t m = 0;
      double mCorr = 0.0;
      for (size_t j = 0; j < 26; ++j) 
      {
        double corr = 0.0;
        char c = 'A' + j;
        for (size_t k = 0; k < 26; ++k) 
        {
          int d = (freqs[i][k].first - c + 26) % 26;
          corr += freqs[i][k].second * targets[d];
        }

        if (corr > mCorr) 
        {
          m = j;
          mCorr = corr;
        }
      }
      key += m + 'A';
    }

    string result = "";
    for (size_t i = 0; i < cleaned.size(); ++i)
      result += (cleaned[i] - key[i % key.length()] + 26) % 26 + 'A';

    return make_pair(result, key);
  }
};

int main() 
{
  string input =
    "Qn rvyium, ioijg ltjvprbxvr dgbwvhj qvaf afts xm xyg atjvvv stf mj mvddr. Zp pxz mekbxhp rvbpjo riixuwk vpt Cmxgvègl gzrpty, Jikmsymtj Spzmjmq whh jwkrlwj dg teedkvxuk igxthxvf aiymeia dm gyczpjxvta xu xyg kxwlvt btex, njqro gfwts prukkpai kjm alrxvp dm xyg atjvvv stf. Xyka blxyql xz rfy kpspvf bwl Oruqhrm vzibprrvqdu. Jzplxuk dqzt yiggiilh jvzxukj qn roeickilvj jmaww eczgva uqec alv nmcnxy qn ioi gqbtuxzct hlgigb zlc. Fpkt alv nmcnxy qn ioi jgkglx bgg xz oeqec, alv eqeoii vmma mj tmlymkvmc prkq i rvvigaevrukvv uyddmg vj tqtjtrj, yqio e tqtjtr wqz thgy nmiaii qn ioi bgg. Thgy ewabqe ka ioie oisl yg qn esezpbtex kjii’z fvgv tugiaxilh sa wcl Grgapy gzrpty. Xyg kdki-stmprii vptu figizz xyg kxwlvt btex zp i hpqznig dep vw p Jevuig jmgjmg.";

  array<double, 26> english = {
    0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228,
    0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025,
    0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987,
    0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150,
    0.01974, 0.00074};

  VigenereAnalyser va(english);
  pair<string, string> output = va.analyze(input);

  cout << "Key: " << output.second << endl << endl;
  cout << "Text: " << output.first << endl;
}
