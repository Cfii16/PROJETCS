
def check_password_strength(password)
  return "Inválida" if password.nil? || password.empty?

  has_length = password.length >= 8
  has_upper = password =~ /[A-Z]/
  has_number = password =~ /[0-9]/
  has_symbol = password =~ /[!@#$%^&*]/

  if has_length && has_upper && has_number && has_symbol
    "Forte"
  elsif has_length
    "Média"
  else
    "Fraca"
  end
end

def generate_secure_password
  letters_lower = ('a'..'z').to_a
  letters_upper = ('A'..'Z').to_a
  numbers = ('0'..'9').to_a
  symbols = ['!', '@', '#', '$', '%', '^', '&', '*']

  password = [
    letters_upper.sample,       
    numbers.sample (2),            
    symbols.sample,                
    letters_lower.sample(4)        
  ].flatten.shuffle.join

  password
end

puts "O que queres fazer?"
puts "1 - Criar uma password segura"
puts "2 - Verificar a força de uma password"
print "Escolhe (1 ou 2): "

choice = gets.chomp

if choice == "1"
  new_password = generate_secure_password
  puts "Aqui está a tua password segura: #{new_password}"
elsif choice == "2"
  print "Insere a password para verificar: "
  user_password = gets.chomp
  result = check_password_strength(user_password)
  puts "A password '#{user_password}' é #{result}"
else
  puts "Escolha inválida! Usa 1 ou 2."
end