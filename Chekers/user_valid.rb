def user_valid(user)
return "Invalid" if user.nil? || user.empty?

has_length = user.length >= 8

if has_length
	"É válido"

else 
	"Não é válido"

end
end

puts "Digita o user name"
resposta = gets.chomp;

if user_valid(resposta) == "Válido"
  puts "É válido"
else
  puts "Não é válido, username necessita minimo de 8 caracteres!"
end