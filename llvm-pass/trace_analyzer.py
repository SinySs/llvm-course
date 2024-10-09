import collections
import matplotlib.pyplot as plt
import sys

def read_instructions_from_file(filename):
    with open(filename, 'r', encoding='utf-8') as f:
        instructions = [line.strip() for line in f if line.strip()]
    return instructions

def count_frequencies(instructions):
    instruction_freq = collections.Counter(instructions)
    pair_freq = collections.Counter(zip(instructions, instructions[1:]))
    triple_freq = collections.Counter(zip(instructions, instructions[1:], instructions[2:]))
    
    return instruction_freq, pair_freq, triple_freq

def plot_frequencies(freq_dict, title, top_n=10):
    most_common = freq_dict.most_common(top_n)
    labels, counts = zip(*most_common)

    plt.figure(figsize=(10, 5))
    plt.bar(range(len(labels)), counts, tick_label=[str(label) for label in labels])
    plt.xticks(rotation=45, ha="right")
    plt.title(title)
    plt.ylabel('Frequency')
    plt.tight_layout()
    plt.show()

def main(filename, count_type):
    instructions = read_instructions_from_file(filename)

    instruction_freq, pair_freq, triple_freq = count_frequencies(instructions)

    if count_type == '1':
        print(f"Top 10 most common Instructions: {instruction_freq.most_common(10)}")
        plot_frequencies(instruction_freq, "Top 10 Most Common Instructions")
    elif count_type == '2':
        print(f"Top 10 most common pairs: {pair_freq.most_common(10)}")
        plot_frequencies(pair_freq, "Top 10 Most Common Instruction Pairs")
    elif count_type == '3':
        print(f"Top 10 most common triples: {triple_freq.most_common(10)}")
        plot_frequencies(triple_freq, "Top 10 Most Common Instruction Triples")
    elif count_type == "all":
        print(f"Top 10 most common Instructions: {instruction_freq.most_common(10)}")
        plot_frequencies(instruction_freq, "Top 10 Most Common Instructions")

        print(f"Top 10 most common pairs: {pair_freq.most_common(10)}")
        plot_frequencies(pair_freq, "Top 10 Most Common Instruction Pairs")

        print(f"Top 10 most common triples: {triple_freq.most_common(10)}")
        plot_frequencies(triple_freq, "Top 10 Most Common Instruction Triples")

if __name__ == "__main__":
    if len(sys.argv) >= 3:
        filename = sys.argv[1]
        count_type = sys.argv[2]
    else:
        print("Usage: python script_name.py <filename> <count_type>")
        print("count_type should be one of 1, 2, 3 or all")
        sys.exit(1)

    main(filename, count_type)