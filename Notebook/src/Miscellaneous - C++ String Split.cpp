vector<string> split(string source, string pattern) {
  unsigned int i, base = 0;
  vector<string> ret;
  string buff;

  for(i = 0; i < source.size(); i++) {
    if(source.substr(i, pattern.size()) == pattern) {
      ret.push_back(buff);
      i += pattern.size() - 1;
      buff.clear();
    } else {
      buff += source[i];
    }
  }
  ret.push_back(buff);
  return ret;
}
