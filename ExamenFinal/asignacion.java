import java.util.Arrays;
import java.util.Scanner;
 
class Asignacion
{
    private final int[][] costMatrix;
    private final int     rows, cols, dim;
    private final int[]   labelByWorker, labelByJob;
    private final int[]   minSlackWorkerByJob;
    private final int[]   minSlackValueByJob;
    private final int[]   matchJobByWorker, matchWorkerByJob;
    private final int[]   parentWorkerByCommittedJob;
    private final boolean[]  committedWorkers;
 
    public Asignacion(int[][] costMatrix)
    {
        this.dim = Math.max(costMatrix.length, costMatrix[0].length);
        this.rows = costMatrix.length;
        this.cols = costMatrix[0].length;
        this.costMatrix = new int[this.dim][this.dim];
        for (int w = 0; w < this.dim; w++)
        {
            if (w < costMatrix.length)
            {
                if (costMatrix[w].length != this.cols)
                {
                    throw new IllegalArgumentException("Irregular cost matrix");
                }
                this.costMatrix[w] = Arrays.copyOf(costMatrix[w], this.dim);
            }
            else
            {
                this.costMatrix[w] = new int[this.dim];
            }
        }
        labelByWorker = new int[this.dim];
        labelByJob = new int[this.dim];
        minSlackWorkerByJob = new int[this.dim];
        minSlackValueByJob = new int[this.dim];
        committedWorkers = new boolean[this.dim];
        parentWorkerByCommittedJob = new int[this.dim];
        matchJobByWorker = new int[this.dim];
        Arrays.fill(matchJobByWorker, -1);
        matchWorkerByJob = new int[this.dim];
        Arrays.fill(matchWorkerByJob, -1);
    }
 
    protected void computeInitialFeasibleSolution()
    {
        for (int j = 0; j < dim; j++)
        {
            labelByJob[j] = Integer.MAX_VALUE;
        }
        for (int w = 0; w < dim; w++)
        {
            for (int j = 0; j < dim; j++)
            {
                if (costMatrix[w][j] < labelByJob[j])
                {
                    labelByJob[j] = costMatrix[w][j];
                }
            }
        }
    }
 
    public int[] execute()
    {
        reduce();
        computeInitialFeasibleSolution();
        greedyMatch();
        int w = fetchUnmatchedWorker();
        while (w < dim)
        {
            initializePhase(w);
            executePhase();
            w = fetchUnmatchedWorker();
        }
        int[] result = Arrays.copyOf(matchJobByWorker, rows);
        for (w = 0; w < result.length; w++)
        {
            if (result[w] >= cols)
            {
                result[w] = -1;
            }
        }
        return result;
    }
 
    protected void executePhase()
    {
        while (true)
        {
            int minSlackWorker = -1, minSlackJob = -1;
            int minSlackValue = Integer.MAX_VALUE;
            for (int j = 0; j < dim; j++)
            {
                if (parentWorkerByCommittedJob[j] == -1)
                {
                    if (minSlackValueByJob[j] < minSlackValue)
                    {
                        minSlackValue = minSlackValueByJob[j];
                        minSlackWorker = minSlackWorkerByJob[j];
                        minSlackJob = j;
                    }
                }
            }
            if (minSlackValue > 0)
            {
                updateLabeling(minSlackValue);
            }
            parentWorkerByCommittedJob[minSlackJob] = minSlackWorker;
            if (matchWorkerByJob[minSlackJob] == -1)
            {
                int committedJob = minSlackJob;
                int parentWorker = parentWorkerByCommittedJob[committedJob];
                while (true)
                {
                    int temp = matchJobByWorker[parentWorker];
                    match(parentWorker, committedJob);
                    committedJob = temp;
                    if (committedJob == -1)
                    {
                        break;
                    }
                    parentWorker = parentWorkerByCommittedJob[committedJob];
                }
                return;
            }
            else
            {
                int worker = matchWorkerByJob[minSlackJob];
                committedWorkers[worker] = true;
                for (int j = 0; j < dim; j++)
                {
                    if (parentWorkerByCommittedJob[j] == -1)
                    {
                        int slack = costMatrix[worker][j]
                                - labelByWorker[worker] - labelByJob[j];
                        if (minSlackValueByJob[j] > slack)
                        {
                            minSlackValueByJob[j] = slack;
                            minSlackWorkerByJob[j] = worker;
                        }
                    }
                }
            }
        }
    }
 
    protected int fetchUnmatchedWorker()
    {
        int w;
        for (w = 0; w < dim; w++)
        {
            if (matchJobByWorker[w] == -1)
            {
                break;
            }
        }
        return w;
    }
 
    protected void greedyMatch()
    {
        for (int w = 0; w < dim; w++)
        {
            for (int j = 0; j < dim; j++)
            {
                if (matchJobByWorker[w] == -1
                        && matchWorkerByJob[j] == -1
                        && costMatrix[w][j] - labelByWorker[w] - labelByJob[j] == 0)
                {
                    match(w, j);
                }
            }
        }
    }
 
    protected void initializePhase(int w)
    {
        Arrays.fill(committedWorkers, false);
        Arrays.fill(parentWorkerByCommittedJob, -1);
        committedWorkers[w] = true;
        for (int j = 0; j < dim; j++)
        {
            minSlackValueByJob[j] = costMatrix[w][j] - labelByWorker[w]
                    - labelByJob[j];
            minSlackWorkerByJob[j] = w;
        }
    }
 
    protected void match(int w, int j)
    {
        matchJobByWorker[w] = j;
        matchWorkerByJob[j] = w;
    }
 
    protected void reduce()
    {
        for (int w = 0; w < dim; w++)
        {
            int min = Integer.MAX_VALUE;
            for (int j = 0; j < dim; j++)
            {
                if (costMatrix[w][j] < min)
                {
                    min = costMatrix[w][j];
                }
            }
            for (int j = 0; j < dim; j++)
            {
                costMatrix[w][j] -= min;
            }
        }
        int[] min = new int[dim];
        for (int j = 0; j < dim; j++)
        {
            min[j] = Integer.MAX_VALUE;
        }
        for (int w = 0; w < dim; w++)
        {
            for (int j = 0; j < dim; j++)
            {
                if (costMatrix[w][j] < min[j])
                {
                    min[j] = costMatrix[w][j];
                }
            }
        }
        for (int w = 0; w < dim; w++)
        {
            for (int j = 0; j < dim; j++)
            {
                costMatrix[w][j] -= min[j];
            }
        }
    }
 
    protected void updateLabeling(int slack)
    {
        for (int w = 0; w < dim; w++)
        {
            if (committedWorkers[w])
            {
                labelByWorker[w] += slack;
            }
        }
        for (int j = 0; j < dim; j++)
        {
            if (parentWorkerByCommittedJob[j] != -1)
            {
                labelByJob[j] -= slack;
            }
            else
            {
                minSlackValueByJob[j] -= slack;
            }
        }
    }
 

    public int getMaxValue(int[][] matriz) {
        int maxValue = 0;
        for(int i = 0;i < matriz[0].length; i++) {
            for(int j = 0;j < matriz[0].length;j++) {
                maxValue = Math.max(maxValue, matriz[i][j]);
            }
        }
        return maxValue;
    }

    public int[][] minMatriz(int[][] matriz) {
        int maxValue = getMaxValue(cost);
        int[][] newCost = new int[matriz[0].length][matriz[0].length];
        for(int i = 0;i < matriz[0].length; i++) {
            for(int j = 0;j < matriz[0].length;j++) {
                newCost[i][j] = maxValue - matriz[i][j];
            }
        }
    }

    public static void main(String[] args)
    {
        int[][] cost = {{9,9,9,9},{3,4,3,8},{2,3,1,9},{0,0,0,9}};
        
        int [][] minCost = minMatriz(cost)
        Asignacion hbm = new Asignacion(cost);
        int[] result = hbm.execute();
        System.out.println("Bipartite Matching: " + Arrays.toString(result));
        sc.close();
    }
}