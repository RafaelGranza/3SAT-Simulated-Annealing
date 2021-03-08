from state import State

def get_state():
   test_data = []
   while 1:
      try:
         s = input()
         if s is "%": break
         test_data.append(s)
      except:
         break

   formula = []
   for rec in test_data:
      try:
         rec=rec.strip()
         junk_list = []

         ## record has to start with a number or a minus sign
         if (rec[0].isdigit()) or (rec[0].startswith("-")):
            substrs = rec.split()
            for num in substrs:
               try:
                  num_int = int(num)
                  if num_int < 0:
                     junk_list.append( (abs(num_int), 0) )
                  elif num_int > 0:         ## eliminate zero
                     junk_list.append( (num_int, 1) )
               except:
                  print("error converting", rec)

            formula.append(junk_list)
      except:
         break
   return State(formula)
