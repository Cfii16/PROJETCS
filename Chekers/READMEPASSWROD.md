# Password Checker and Generator

Um script em Ruby que permite criar passwords seguras ou verificar a força de passwords existentes. Desenvolvido como uma ferramenta simples de cibersegurança.

## Descrição
Este programa interativo:
- **Cria** uma password segura com pelo menos 8 caracteres, incluindo uma letra maiúscula, um número e um caractere especial.
- **Verifica** a força de uma password inserida pelo utilizador, classificando-a como "Forte", "Média" ou "Fraca" com base em critérios específicos.

### Critérios de Força
- **Forte**: Mínimo de 8 caracteres, com pelo menos uma letra maiúscula, um número e um caractere especial.
- **Média**: Pelo menos 8 caracteres, mas falta um ou mais dos critérios acima (maiúscula, número ou símbolo).
- **Fraca**: Menos de 8 caracteres, independentemente dos outros critérios.
- **Inválida**: Password vazia ou nula.

## Requisitos
- Ruby instalado (versão 2.7 ou superior recomendada). Verifica com `ruby --version`.

## Como Usar
1. Salva o script como `password_checker.rb`.
2. No terminal, navega até ao diretório do arquivo.
3. Executa: `ruby password_checker.rb`.
4. Segue as instruções no ecrã:
   - Escolhe `1` para criar uma password segura.
   - Escolhe `2` para verificar uma password existente.

## Exemplos
### Criar uma Password

## Casos de Uso Reais
- **Cibersegurança Pessoal**: Gera passwords fortes para contas online ou verifica se as tuas passwords atuais são seguras.
- **Educação**: Demonstra como critérios simples (tamanho, variedade de caracteres) impactam a segurança de passwords.
- **Testes Rápidos**: Usa em workshops ou auditorias básicas para avaliar passwords de forma interativa.

## Notas
- A password gerada tem exatamente 8 caracteres por padrão, mas pode ser ajustada no código (modifica `sample(5)` na função `generate_secure_password` para mais letras).
- Os caracteres especiais estão limitados a `!@#$%^&*`, mas podes expandir a lista no código.
